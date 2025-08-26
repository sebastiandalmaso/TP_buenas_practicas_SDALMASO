#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 10000 /* Definición de constante para la cantidad máxima de libros */

/* 
Estructura que almacena los datos de un libro:
- titulo: título del libro
- autor: nombre del autor
- anio: año de edición 
*/

struct datos_libros {
	char titulo[100];
	char autor[50];
	int anio;
};

/* DECLARACIÓN DE FUNCIONES */
void menu(int *opcion);
void cargar_datos(struct datos_libros libros[MAX_LIBROS], int *cantidad);
void mostrar_datos(struct datos_libros libros[MAX_LIBROS], int *cantidad);
void guardar_archivo(struct datos_libros libros[MAX_LIBROS], int *cantidad);
void buscarlibro(struct datos_libros libros[MAX_LIBROS], int *cantidad);

struct datos_libros libros[MAX_LIBROS];
/*
MAIN del programa. Muestra el menú y ejecuta las opciones según lo que elija el usuario.
*/
int main(int argc, char *argv[]) {
	int opcion = 0, cantidad = 0;
	do {
		menu(&opcion);
		switch(opcion) {
		case 1:
			cargar_datos(libros, &cantidad);
			break;
		case 2:
			mostrar_datos(libros, &cantidad);
			break;
		case 3:
			buscarlibro(libros, &cantidad);
			break;
		case 4:
			guardar_archivo(libros, &cantidad);
			break;
		case 5:
			/* buscarLibroArchivo(libros);  Función no implementada en el examen */
			break;
		case 6:
			break;
		default:
			printf("Opcion invalida.\n");
		}
	} while(opcion != 6);
	return 0;
}
/* 
Función que muestra el menú principal y recibe la opción elegida por el usuario.
Entrada: puntero a opción
Salida: actualiza el valor de opción
*/
void menu(int *opcion) {
	printf("\n1. Cargar Libros\n");
	printf("2. Listar Libros en pantalla\n");
	printf("3. Buscar libro desde teclado\n");
	printf("4. Guardar lista de libros en archivo\n");
	printf("5. Buscar libro desde archivo\n");
	printf("6. Salir\n");
	printf("Elija opcion: ");
	scanf("%d", opcion);
	getchar();/* Limpiar el buffer del teclado */
}
/* 
Función que permite al usuario cargar uno o más libros desde teclado.
Entrada: arreglo de libros, puntero a cantidad de libros
Salida: actualiza el arreglo con los libros ingresados
*/
void cargar_datos(struct datos_libros libros[MAX_LIBROS], int *cantidad) {
	int continuar = 1;
	
	while (continuar) {
		printf("\nIngrese título del libro: ");
		fgets(libros[*cantidad].titulo, sizeof(libros[*cantidad].titulo), stdin);
		libros[*cantidad].titulo[strcspn(libros[*cantidad].titulo, "\n")] = 0;
		
		printf("Ingrese autor del libro: ");
		fgets(libros[*cantidad].autor, sizeof(libros[*cantidad].autor), stdin);
		libros[*cantidad].autor[strcspn(libros[*cantidad].autor, "\n")] = 0;
		
		printf("Ingrese año de edición: ");
		scanf("%d", &libros[*cantidad].anio);
		getchar();
		
		(*cantidad)++;  /* Incrementar contador de libros */
		
		printf("\n[1] MENU | [2] AGREGAR OTRO LIBRO: ");
		scanf("%d", &continuar);
		getchar();
		
		continuar = (continuar == 2);  /* Si elige 2, sigue cargando */
	}
}
/* 
Función que muestra todos los libros cargados hasta el momento.
Entrada: arreglo de libros, puntero a cantidad de libros
Salida: impresión en pantalla
*/
void mostrar_datos(struct datos_libros libros[MAX_LIBROS], int *cantidad) {
	printf("\n======= LISTA DE LIBROS =======\n");
	
	for (int i = 0; i < *cantidad; i++) {
		printf("\nLibro %d:\n", i + 1);
		printf("Título: %s\n", libros[i].titulo);
		printf("Autor: %s\n", libros[i].autor);
		printf("Año de edición: %d\n", libros[i].anio);
	}
}
/* 
Función que permite buscar libros por título, autor o año.
Entrada: arreglo de libros, puntero a cantidad de libros
Salida: muestra en pantalla los libros coincidentes
*/
void buscarlibro(struct datos_libros libros[MAX_LIBROS], int *cantidad) {
	int opcion = 0;
	
	do {
		printf("Ingrese que parametro del libro desea buscar:\n");
		printf("1. Titulo\n2. Autor\n3. Anio\n4. Salir\nOpcion: ");
		scanf("%d", &opcion);
		getchar();
		
		switch (opcion) {
		case 1: {
			char titulo_buscado[100];
			printf("Ingrese el Titulo a buscar: ");
			gets(titulo_buscado);
			int encontrado = 0;
			for (int i = 0; i < *cantidad; i++) {
				if (strcmp(libros[i].titulo, titulo_buscado) == 0) {
					printf("\n--- Libro encontrado ---\n");
					printf("Titulo: %s\n", libros[i].titulo);
					printf("Autor: %s\n", libros[i].autor);
					printf("Anio: %d\n", libros[i].anio);
					encontrado = 1;
				}
			}
			if (!encontrado)
				printf("\n*** Libro no encontrado. ***\n");
			break;
		}
		
		case 2: {
			char autor_buscado[100];
			printf("Ingrese el Autor a buscar: ");
			gets(autor_buscado);
			
			int encontrado = 0;
			for (int i = 0; i < *cantidad; i++) {
				if (strcmp(libros[i].autor, autor_buscado) == 0) {
					printf("\n--- Libro encontrado ---\n");
					printf("Titulo: %s\n", libros[i].titulo);
					printf("Autor: %s\n", libros[i].autor);
					printf("Anio: %d\n", libros[i].anio);
					encontrado = 1;
				}
			}
			if (!encontrado)
				printf("\n*** Libro no encontrado. ***\n");
			break;
		}
		
		case 3: {
			int anio_buscado;
			printf("Ingrese el Anio a buscar: ");
			scanf("%d", &anio_buscado);
			
			int encontrado = 0;
			for (int i = 0; i < *cantidad; i++) {
				if (anio_buscado == libros[i].anio) {
					printf("\n--- Libro encontrado ---\n");
					printf("Titulo: %s\n", libros[i].titulo);
					printf("Autor: %s\n", libros[i].autor);
					printf("Anio: %d\n", libros[i].anio);
					encontrado = 1;
				}
			}
			if (!encontrado)
				printf("\n*** Libro no encontrado. ***\n");
			break;
		}
		
		case 4:
			printf("Saliendo del buscador...\n");
			break;
			
		default:
			printf("Opcion invalida.\n");
			break;
		}
		
	} while(opcion != 4);
}
/* 
Función que guarda todos los libros en un archivo de texto llamado "Datoslibros.txt".
Entrada: arreglo de libros, puntero a cantidad de libros
Salida: archivo con la información
*/
void guardar_archivo(struct datos_libros libros[MAX_LIBROS], int *cantidad) {
	FILE *archivo = fopen("Datoslibros.txt", "w");
	
	/* Verifica si el archivo se abrió correctamente */
	if (!archivo) {
		printf("Error al abrir el archivo para escritura.\n");
		return;
	}
	
	for (int i = 0; i < *cantidad; i++) {
		fprintf(archivo, "%s\n", libros[i].titulo);
		fprintf(archivo, "%s\n", libros[i].autor);
		fprintf(archivo, "%d\n", libros[i].anio);
	}
	
	fclose(archivo);
	printf("Archivo guardado exitosamente.\n");
}
