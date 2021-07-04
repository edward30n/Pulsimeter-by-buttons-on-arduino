/* Ruler 1         2         3         4         5         6         7        */

/******************************************************************************/
/*              _     _                  _                                    */
/*             | |   (_)                | |                                   */                  
/*    _ __  _   _| |___ _ _ __ ___   ___| |_ _ __ ___                         */
/*   | '_ \| | | | / __| | '_ ` _ \ / _ \ __| '__/ _ \                        */
/*   | |_) | |_| | \__ \ | | | | | |  __/ |_| | | (_) |                       */
/*     | .__/ \__,_|_|___/_|_| |_| |_|\___|\__|_|\___/                        */
/*   | |                                                                      */
/*   |_|                                                                      */
/*	                _       _                                                 */
/*	               | |     (_)                                                */
/*	   __ _ _ __ __| |_   _ _ _ __   ___      _   _ _ __   ___                */
/*	  / _` | '__/ _` | | | | | '_ \ / _ \    | | | | '_ \ / _ \               */
/*	 | (_| | | | (_| | |_| | | | | | (_) |   | |_| | | | | (_) |              */
/*	  \__,_|_|  \__,_|\__,_|_|_| |_|\___/     \__,_|_| |_|\___/               */
/*                                                                            */
/*    Written in 2021 by Camilo Ramirez, <camilo_ramirez@javeriana.edu.co>    */
/*                       Edward Duarte, <edwardduarte@javeriana.edu.co>       */
/*                       David Orozco, <davidorozco@javeriana.edu.co>         */
/*                       Nicolas Pedraza <pedraza_n@javeriana.edu.co>         */
/*                                                                            */
/*                                                                            */
/* Letters created with "Big" font using http://www.network-science.de/ascii/ */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*    Pulsimetro arduino uno provides the cardiac pulse of evereyone.         */
/*                                                                            */
/*    Copyright (C) 2021 Camilo Ramirez                                       */
/*                       Edward Duarte                                        */
/*                       David Orozco                                         */
/*                       Nicolas Pedraza                                      */
/*                                                                            */
/*    This file is part of DC Solver.                                         */
/*                                                                            */
/*    Pulsimetro arduino uno is free software: you can redistribute it        */
/*    and/or modify it under the terms of the GNU General Public License as   */
/*    published by the Free Software Foundation, either version 3 of the      */
/*    License, or (at your option) any later version.                         */
/*                                                                            */
/*    Pulsimetro arduino uno is distributed in the hope that it will be       */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of          */
/*    useful,MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    */
/*    GNU General Public License for more details.                            */
/*                                                                            */
/*    You should have received a copy of the GNU General Public License       */
/*    along with DC Solver.  If not, see <http://www.gnu.org/licenses/>.      */
/*                                                                            */
/******************************************************************************/

/*********************************  digitos.h *********************************/
/*                                                                            */
/*   Origin:  Modulo diseñado, testado e implementado por                     */
/*                        Camilo Ramírez                                      */
/*                        Edward Duarte                                       */
/*                        David Orozco                                        */
/*                        Nicolas Pedraza                                     */
/*                                                                            */
/*   Notes:   None                                                            */
/*                                                                            */
/*   Register of Revisions (Debugging Process):                               */
/*                                                                            */
/*   DATE       RESPONSIBLE  COMMENT                                          */
/*   -----------------------------------------------------------------------  */
/*   May 16/21  C.Ramirez                                                     */
/*              E.Duarte                                                      */
/*              D.Orozco                                                      */
/*              N.Pedraza   Initial implementation                            */
/*                                                                            */
/******************************************************************************/

#ifndef _DIGITOS_H
#define _DIGITOS_H 

/**************************** Symbolic  Constants *****************************/

/* --------------------- Predefined Sizes of Matrices ----------------------- */

/************************** Prototypes of Functions ***************************/

/* ---------------------------- Public Functions ---------------------------- */


/*FN***************************************************************************/
/*                                                                            */
/*   void dividirDig(int dig[4],int base)                                     */
/*                                                                            */
/*   Propuse:    Tiene la función encargada de separar los                    */
/*               digitos de los BPM                                           */
/*                                                                            */
/*   Return:  Null                                                            */
/*                                                                            */
/*   Register of Revisions (June 6 2021):                                     */
/*                                                                            */
/*   DATE       RESPONSIBLE  COMMENT                                          */
/*   -----------------------------------------------------------------------  */
/*   JUNE 06/21 C.Ramirez                                                     */
/*              E.Duarte                                                      */
/*              D.Orozco                                                      */
/*              N.Pedraza                                                     */
/*              J.Girarldo                                                    */
/*                                                                            */
/******************************************************************************/

// Función encargada de  dividir los digitos en cada parte de la matriz "dig"
void dividirDig(int dig[4],int base){
      dig[0] = base / 1000;
      dig[1] = (base / 100) - (dig[0] * 10);
      dig[2] = (base / 10) - (dig[0] * 100) - (dig[1] * 10);
      dig[3] = base - (dig[0] * 1000) - (dig[1] * 100) - (dig[2] * 10);
}
#endif  // _DIGITOS_H
