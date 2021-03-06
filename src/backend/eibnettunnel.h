/*
    EIBD eib bus access and management daemon
    Copyright (C) 2005-2011 Martin Koegler <mkoegler@auto.tuwien.ac.at>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef EIBNET_TUNNEL_H
#define EIBNET_TUNNEL_H

#include "layer2.h"
#include "eibnetip.h"

class EIBNetIPTunnel:public Layer2
{
  EIBNetIPSocket *sock;
  struct sockaddr_in caddr;
  struct sockaddr_in daddr;
  struct sockaddr_in saddr;
  struct sockaddr_in raddr;

  Queue < CArray > send_q;
  int dataport;
  bool NAT;
// main loop internal vars
  int channel = -1;
  int mod = 0;
  int rno = 0;
  int sno = 0;
  int heartbeat = 0;
  int drop = 0;
  int retry = 0;

  float send_delay;
  ev::timer timeout; void timeout_cb(ev::timer &w, int revents);
  ev::timer sendtimeout; void sendtimeout_cb(ev::timer &w, int revents);
  ev::timer conntimeout; void conntimeout_cb(ev::timer &w, int revents);
  ev::async trigger; void trigger_cb(ev::async &w, int revents);
  
  bool support_busmonitor;
  bool connect_busmonitor;
  void on_recv_cb(EIBNetIPPacket *p);

  const char *Name() { return "eibnettunnel"; }

  inline EIBnet_ConnectRequest get_creq() { 
    EIBnet_ConnectRequest creq;

    creq.nat = saddr.sin_addr.s_addr == 0;
    creq.caddr = saddr;
    creq.daddr = saddr;
    creq.CRI.resize (3);
    creq.CRI[0] = 0x04;
    creq.CRI[1] = 0x02;
    creq.CRI[2] = 0x00;
    return creq;
  } 

public:
  EIBNetIPTunnel (const char *dest, int port, int sport, const char *srcip,
                  int dataport, L2options *opt);
  virtual ~EIBNetIPTunnel ();
  bool init (Layer3 *l3);

  bool enterBusmonitor ();
  bool leaveBusmonitor ();

  void send_L_Data (LDataPtr  l);
};


#endif
