# Operaciones con Listas Enlazadas – Estructuras de Datos

**Autor:** Fabián Nicolás Díaz Navarrete  
**Fecha:** Enero 2026  

Implementación en C++ de distintas variantes de listas enlazadas y sus operaciones básicas, con el objetivo de comprender su funcionamiento interno y manejo de memoria.

El proyecto incluye:

- Lista enlazada simple  
- Lista enlazada doble  
- Lista enlazada simple circular  
- Lista enlazada doble circular  

Para cada estructura se implementan las operaciones de:

- Inserción de nodos  
- Búsqueda de datos  
- Eliminación de nodos  

---

## Compilación

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic Nodo.cpp NodoNexoDoble.cpp main.cpp -o Listas
./Listas
