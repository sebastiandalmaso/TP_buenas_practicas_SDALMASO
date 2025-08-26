#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 10000

struct datos_libros {
	char titulo[100];
	char autor[50];
	int anio;
};

void menu(int *opcion);
void cargardatos(struct datos_libros libros[MAX_LIBROS], int *cantidad);
void mostrardatos(struct datos_libros libros[MAX_LIBROS], int *cantidad);
void guardararchivo(struct datos_libros libros[MAX_LIBROS], int *cantidad);
void buscarlibro(struct datos_libros libros[MAX_LIBROS], int *cantidad);

struct datos_libros libros[MAX_LIBROS];

int main(int argc, char *argv[]) {
	int opcion = 0, cantidad = 0;
	do {
		menu(&opcion);
		switch(opcion) {
		case 1:
			cargardatos(libros, &cantidad);
			break;
		case 2:
			mostrardatos(libros, &cantidad);
			break;
		case 3:
			buscarlibro(libros, &cantidad);
			break;
		case 4:
			guardararchivo(libros, &cantidad);
			break;
		case 5:
			// buscarLibroArchivo(libros);
			break;
		case 6:
			break;
		default:
			printf("Opcion invalida.\n");
		}
	} while(opcion != 6);
	return 0;
}

void menu(int *opcion) {
	printf("\n1. Cargar Libros\n");
	printf("2. Listar Libros en pantalla\n");
	printf("3. Buscar libro desde teclado\n");
	printf("4. Guardar lista de libros en archivo\n");
	printf("5. Buscar libro desde archivo\n");
	printf("6. Salir\n");
	printf("Elija opcion: ");
	scanf("%d", opcion);
	getchar();
}

void cargardatos(struct datos_libros libros[MAX_LIBROS], int *cantidad) {
	int salir = 0, i=0;
	while (!salir) {
		printf("\nIngrese titulo libro: ");
		gets(libros[i].titulo);
		printf("\nIngrese autor libro: ");
		gets(libros[i].autor);
		printf("\nIngrese anio edicion: ");
		scanf("%d",&libros[i].anio);
		getchar();
		i++;
		(*cantidad=i);
		
		printf("\n[1] MENU | [2] AGREGAR OTRO LIBRO: ");
		scanf("%d", &salir);
		getchar();
		if (salir == 1) {
			salir = 1;
		} else {
			salir = 0;
		}
	}
}

void mostrardatos(struct datos_libros libros[MAX_LIBROS], int *cantidad) {
	printf("\n======= LISTA DE LIBROS =======\n");
	for (int i=0; i<*cantidad; i++) {
		printf("\nLibro %d:\n", i + 1);
		printf("Titulo:");
		puts(libros[i].titulo);
		printf("Autor:");
		puts(libros[i].autor);
		printf("Anio de edicion: %d\n", libros[i].anio);
	}
}
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
void guardararchivo(struct datos_libros libros[MAX_LIBROS],int *cantidad){
	int i;
	FILE *puntero_archivos;
	puntero_archivos = fopen("Datoslibros.txt","w");
		for(i=0;i<*cantidad;i++){
			fprintf(puntero_archivos,"%s\n", libros[i].titulo);
			fprintf(puntero_archivos,"%s\n", libros[i].autor);
			fprintf(puntero_archivos,"%d\n",libros[i].anio);
		}
	fclose(puntero_archivos);
}
