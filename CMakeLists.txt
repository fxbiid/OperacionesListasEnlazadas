cmake_minimum_required(VERSION 4.0)
project(ListasEnlazadas)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListasEnlazadas main.cpp
        Nodo.cpp
        Nodo.h
        NodoNexoDoble.cpp
        NodoNexoDoble.h)
