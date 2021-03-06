/* packet-http2.h
 * Routines for HTTP2 dissection
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef __PACKET_HTTP2_H__
#define __PACKET_HTTP2_H__

int dissect_http2_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_ );

/** Get header value from current or the other direction stream.
 * Return the value of a header if it appear in previous HEADERS or PROMISE frames in
 * current or the other direction stream. Subdissector may invoke this function to get http2
 * header value.
 * @param pinfo  packet info pointer. Http2 dissector passes it to subdissector
 *               when dissecting http2.data.data.
 * @param name   the name of header.
 * @param the_other_direction  FALSE means from current direction stream, TRUE from the other.
 * @return  NULL if header was not found. Or header value. Note: the value is allocated
 *          by wmem_packet_scope().
 */
const gchar* http2_get_header_value(packet_info *pinfo, const gchar* name, gboolean the_other_direction);

#endif

/*
 * Editor modelines  -  http://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */
