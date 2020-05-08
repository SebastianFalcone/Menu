#include<stdlib.h>
#include<string.h>
#include<unistd.h> 
#include<ncurses.h>
#include<sys/io.h>
#include"menu.h"

#define ENTER 10 //ES EL CODIGO ASIGNADO A LA TECLA

int main()
{
	int POS = 0, MENU = 0, modo = 1, key;
	char arch[30] = "archivo.txt";	

	//INICIALIZACION DEL NCURSES
	initscr();		
	echo();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	
	int tam = print_menu(MENU, POS);

	while(1)
	{
		
		key = getch();

		switch(key)
		{
			
			case KEY_DOWN:
				POS++;
				if(POS >= tam)
					POS = 0;	

			break;
							
			case KEY_UP:
				POS--;
				if(POS < 0)
					POS = tam-1; 
			break;


			case ENTER:
				//SEGUN DONDE ESTE PARADO, EL ENTER HARA DISTINTAS COSAS (VER DIAGRAMA DEL MENU). ME BASO EN UN SISTEMA DE CORDENAS (MENU,POS)
				switch(MENU)
				{

					//MENU PRINCIPAL (MENU = 0)
					case 0:

						//INICIA EL PROGRAMA
						if(POS == 0)
						{	
							programa_principal(arch,modo);
							sleep(1);
						}

						//ABRIR EL MENU DE CONFIGURACIONES
						else if(POS == 1)
						{
							MENU = 1;
							POS  = 0;
						}

						//INICIO lA PRUEBA PARA CORROBORAR EL MONTAJE CORRECTO DE LOS SERVOS Y EL ULTRASONIDO
						else if(POS == 2)
						{
							print("INICIA LA PRUEBA");
							sleep(1);							
						}

						//SALGO DEL PROGRAMA
						else if(POS == 3)
						{
							print("HASTA LUEGO!");
							sleep(1);
							endwin();
							exit(0);
						}

					break;
					

					//MENU DE CONFIGURACION (MENU = 1)
					case 1:

						//ABRIR EL MENU SELECTOR DE MODOS
						if(POS == 0)
						{
							MENU = 2;
							POS  = 0;
						}

						//CAMBIO EL NOMBRE QUE TENDRA EL ARCHIVO
						else if(POS == 1)
						{
							print("COMO DESEA LLAMAR AL ARCHIVO? ");
							getstr(arch);
							strncat(arch, ".txt", 4);//AGREGO LA EXTENSION CORRESPONDIENTE
						}

						//VUELVO AL MENU PRINCIPAL
						else if(POS == 2)
						{
							MENU = 0;
							POS  = 0;	
						}

					break;	

					//MENU DE MODOS (MENU = 2)
					case 2:

						//SELECCIONAR MODO 1
						if(POS == 0)
							modo = seleccionar_modo(POS);						

						//SELECCIONAR MODO 2
						else if(POS == 1)
							modo = seleccionar_modo(POS);	


						//VOLVER AL MENU DE CONFIGURACION
						else if(POS == 2)
						{
							MENU = 1;
							POS  = 0;
						}	
					
					break;
				}
					

					default:
						//Se presiono una tecla que no hace nada
					break;
		}	

		tam = print_menu(MENU, POS); //SE ACTUALIZA EL MENU Y POR LO TANTO LA VARIABLE TAM			
	}
	
	endwin();
	return 0;	
}
