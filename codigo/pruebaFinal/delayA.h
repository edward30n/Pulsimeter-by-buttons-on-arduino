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

/*********************************  delayA.h **********************************/
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

#ifndef _delayA_H
#define _delayA_H

/**************************** Symbolic  Constants *****************************/

/* --------------------- Predefined Sizes of Matrices ----------------------- */

/************************** Prototypes of Functions ***************************/

/* ---------------------------- Public Functions ---------------------------- */


/*FN***************************************************************************/
/*                                                                            */
/*   void delayA(unsigned long ext)                                           */
/*                                                                            */
/*   Propuse:   Tiene la función encargada de esperar los segundos            */
/*              indicados para dar el resultado                               */
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
// Variables para el funcioanmiento basico del delay con el fin de mantener una
//vista de la pantalla
unsigned long antes = 0, despues = 0;
int casosA = 1;
void delayA(unsigned long ext){
      casosA=1;
      antes =millis();
      despues = millis();
      while(casosA==1){
      switch (casosA) {
        case 1:
          if (antes - despues < ext) {
            antes = millis();
            casosA = 1;

          }
          else {
            casosA=2;
          }
          break;
      }
      }
}
#endif  // _delayA_H
