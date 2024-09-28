//Include this library to be able to make calls in shiva2.upc.es
//#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Special structure for storing query results
	MYSQL_RES *result;
	MYSQL_ROW row;
	
	//We create a connection to the MYSQL server
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf("Error creating connection: %u %s\n",
			   mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//initialize the connection
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "Juego",0, NULL, 0);
	if (conn==NULL) {
		printf("Error initializing connection: %u %s\n",
			   mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	int partida;
	printf("Dame el identificador de una partida\n");
	scanf("%d", &partida);
	
	char query[300];
	//strcpy (query,"SELECT Jugador.Nombre FROM Jugador,Participacion WHERE Participacion.Id_partida = %d");
	//strcat (query, partida);
	//strcat (query,"'AND Jugador.Id_Jugador = Participacion.Id_Jugador");
	
	sprintf(query, "SELECT Jugador.Nombre FROM Jugador, Participacion WHERE Participacion.Id_partida = %d AND Jugador.Id_jugador = Participacion.Id_jugador", partida);
	
	err=mysql_query (conn, query);
	if (err!=0) {
		printf ("Error while querying data from database %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	
	result = mysql_store_result(conn);
	if (result == NULL) {
		printf("No data was obtained in the query\n");
	} else {
		int cont = 0;
		while ((row = mysql_fetch_row(result)) != NULL) {
			printf("%s\n", row[0]);
			cont++;
		}
		printf("Total de jugadores en la partida: %d\n", cont);
	}
	
	mysql_free_result(result);
	mysql_close(conn);
	exit(0);
}	
