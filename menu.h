
/*
ACA ESTAN DEFINIDOS LOS MENUS. 
CADA MENU ES UNA MATRIZ A LA QUE SE ACCEDE DESDE "MENUS" CON LOS PARAMETROS M Y P
M = EN QUE MENU ESTOY
P = EN QUE POSICION DE ESE MENU ESTOY
*/
const char * Menu_Principal[] = {"Inicio", "Configuracion", "Prueba", "Salir"};
const char * Menu_Config[] = {"Modos", "Guardar como...", "Atras"};
const char * Menu_Config_Modos[] = {"Modo 1","Modo 2", "Atras"};

const char ** Menus[] = {Menu_Principal, Menu_Config, Menu_Config_Modos};

class nodo
{
	public:
		nodo();
		~nodo();
	
	private:
		char * titulo;
};

class menu
{
	public:
		menu();
		~menu();
	
	private:
		nodo * sig;
		nodo * ant;
		menu * sig;
		menu * ant;


};

//ESTA FUNCION IMPRIME EL MENU EN EL QUE ESTOY PARADO, RESALTANDO LA OPCION A SELECCIONAR CON ENTER.
int print_menu(int M, int P)
{
	int tam;

	clear();
	refresh();
	
	//TENGO QUE MEDIR EL TAMAÑO DE CADA MENU PARA DESPUES PODER RECORRERLOS EN UN LOOP
	switch(M)
	{
		//Menu_Principal
		case 0:
			tam = sizeof(Menu_Principal)/sizeof(char*);
			printw("MENU PRINCIPAL\n\n");
		break;

		//Menu_Config
		case 1:
			tam = sizeof(Menu_Config)/sizeof(char*);
			printw("Configuraciones\n\n");
		break;

		//Menu_Config_Modos
		case 2:
			tam = sizeof(Menu_Config_Modos)/sizeof(char*);
			printw("Selector de modos\n\n");
		break;


		//Si me salgo de los limites
		default:
			printw("ERROR");
			refresh();
			exit(1);
		break;
	}

	//RECORRO EL MENU EN EL QUE ESTOY, RESALTANDO LA LA POSICION SELECCIONADA
	for(int i=0; i<tam; i++)
	{
		if(P == i)
		{	
			attron(A_STANDOUT); 
			printw("%s\n", Menus[M][i]);
			attroff(A_STANDOUT);
		}
		else
			printw("%s\n", Menus[M][i]);			
	}

	refresh();
	return tam;
}

//========================================================================================================================================================================

//ESTE PRINT SIRVE PARA CREAR MENSAJES SIMPLES EN PANTALLA, AHORRANDO ALGUNAS LINEAS DE CODIGO
void print(const char * mensaje)
{
	clear();
	printw("%s", mensaje);
	refresh();
}

//========================================================================================================================================================================

//ESTA FUNCION ES UTIL SI QUISIESE AMPLIAR EL REPERTORIO DE MODOS
int seleccionar_modo(int POS)
{
	int modo = POS + 1;

	clear();
	printw("MODO %d SELECCIONADO", modo);
	refresh();
	sleep(1);

	//tengo que realizar la actualizacion de las variables de angulos

	return modo;		
}

//========================================================================================================================================================================

//ACA AGREGO LA FUNCIONALIDAD DE CADA MODO
void funciones_modo(int modo)
{
	switch(modo)
	{
		//ESTE MODO ESCANEA UNA SEMIESFERA DE 180 X 90 GRADOS
		case 1:

		break;

		//EN ESTE MODO ELIJO EL ANGULO DE AMBOS SERVOS Y REALIZO UNA MEDICION
		case 2:
		break;


		//SI NO CONTEMPLE TODAS LAS POSIBILIDADES DE LA VARIABLE MODO
		default:
			printw("ERROR");
			refresh();
			exit(1);		
		break;
	}

}

//========================================================================================================================================================================

void programa_principal(char * arch, int modo)
{
	FILE *FP;
	struct puntos punto;

	print("INICIO DEL PROGRAMA! \n\nNo mueva el soporte");

	if((FP = fopen(arch, "wb")) == NULL)
	{
		print("ERROR EN LA APERTURA DEL ARCHIVO");
		sleep(1);
		endwin();
		exit(1);
	}

	sleep(1);

	switch(modo)
	{
		case 1:
			print("MODO 1");
			fwrite(&punto, 1, sizeof(struct puntos), FP);	
		break;

		case 2:
			print("MODO 2");
			fwrite(&punto, 1, sizeof(struct puntos), FP);	
		break;
	}
}

//========================================================================================================================================================================
