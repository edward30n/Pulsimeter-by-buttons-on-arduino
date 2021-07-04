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

/******************************** lecturaBPM.h ********************************/
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

#ifndef _lecturaBPM_H
#define _lecturaBPM_H

/**************************** Symbolic  Constants *****************************/

/* --------------------- Predefined Sizes of Matrices ----------------------- */

/************************** Prototypes of Functions ***************************/

/* ---------------------------- Public Functions ---------------------------- */


/*FN***************************************************************************/
/*                                                                            */
/*   void lecturaBPM(Null)                                                    */
/*                                                                            */
/*   Propuse: Tiene la función encargada de realizar la                       */
/*            logica del caso 1 para evitar el efecto rebote                  */
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

/*
  Botones: Vector que almacena los puertos de entrada de los botones
  BPM:     Vector que almacena los latidos del corazón de cada una de las 4 personas
  lectura: Valor de entrada dado por el pin analogo conectado al boton en cuestión,
  base:    Variable que almacena el valor a imprimir en pantalla
  botonP:  Variable que almacene el pin de un botón
  conta:   Variable que almacena el numero de la persona que se muestra en pantalla
*/
int botones[4] = {A0, A1, A2, A3}, BPM[4] = {0, 0, 0, 0}, lectura = 0, base = 0, botonP = A4, conta = 0;
// Prueba[4]: Centinela del efecto rebote
// PruebaBoton: Centinela del efecto rebote del botón de menu
byte prueba[5] = {0, 0, 0, 0}, pruebaBoton = 0;
/* primeraPulsacionT:    Define el tiempo en que se realiza una pulsación en el pulsador,
   segundaPulsacionT:    Almacena el tiempo de la segunda pulsación,
   intervaloPulsaciones: Almacena la resta entre el timepo de la segunda y la primera pulsación.
*/
unsigned long primeraPulsacionT[4] = {0, 0, 0, 0}, segundaPulsacionT[4] = {0, 0, 0, 0}, intervaloPulsaciones[4] = {0, 0, 0, 0};

/* 
  Función encargada de realizar todo el proceso de la lectura de los latidos por minuto, llamando asi a otra función BPM
  de la librería BPM.h
*/
int lecturaBPM() {
  // Condicional para determinar si el botón 0 no se encuentra oprimido.
  if (analogRead(botones[0]) < 500) {
    prueba[0] = 1;
  }
  // Condicional para determinar si el botón 1 no se encuentra oprimido. 
  if (analogRead(botones[1]) < 500) {
    prueba[1] = 1;
  }
  // Condicional para determinar si el botón 2 no se encuentra oprimido.
  if (analogRead(botones[2]) < 500) {
    prueba[2] = 1;
  }
  // Condicional para determinar si el botón 3 no se encuentra oprimido.
  if (analogRead(botones[3]) < 500) {
    prueba[3] = 1;
  }
  // Condicional para determinar si el botón Princial no se encuentra oprimido.
    if (analogRead(botonP) < 500) {
    pruebaBoton = 1;
  }
  // Condicional para revisar si el botón 0 está siendo oprimido
  if (analogRead(botones[0]) > 500 && prueba[0] == 1) {
    prueba[0] = 0;
    lectura = analogRead(botones[0]);
    base= bpm(lectura, botones[0], &primeraPulsacionT[0], &segundaPulsacionT[0], &intervaloPulsaciones[0], &BPM[0])+1000;
    BPM[0]+=1000;
  }
  // Condicional para revisar si el botón 1 está siendo oprimido
  if (analogRead(botones[1]) > 500 && prueba[1] == 1) {
    prueba[1] = 0;
    lectura = analogRead(botones[1]);
    bpm(lectura, botones[1], &primeraPulsacionT[1], &segundaPulsacionT[1], &intervaloPulsaciones[1], &BPM[1]);
    BPM[1]+=2000;
  }
  // Condicional para revisar si el botón 2 está siendo oprimido
  if (analogRead(botones[2]) > 500 && prueba[2] == 1) {
    prueba[2] = 0;
    lectura = analogRead(botones[2]);
    bpm(lectura, botones[2], &primeraPulsacionT[2], &segundaPulsacionT[2], &intervaloPulsaciones[2], &BPM[2]);
    BPM[2]+=3000;
  }
  // Condicional para revisar si el botón 3 está siendo oprimido
  if (analogRead(botones[3]) > 500 && prueba[3] == 1) {
    prueba[3] = 0;
    lectura = analogRead(botones[3]);
    bpm(lectura, botones[3], &primeraPulsacionT[3], &segundaPulsacionT[3], &intervaloPulsaciones[3], &BPM[3]);
    BPM[3]+=4000;
  }
  // Logica para que a traves del botón principal se realice el cambio del pulso de las personas en pantalla
  if(analogRead(botonP) > 500 && pruebaBoton == 1) {
    pruebaBoton = 0;
    base = BPM[conta];
    conta++;
    if(conta == 4){
      conta = 0;
    }
  }
  return base;
}
#endif  // _lecturaBPM_H
