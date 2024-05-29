from random import randint
import time

if __name__ == '__main__':
    M = 1000 # filas
    N = 1000 # columnas

    matrix = [[randint(0,100) for _ in range(N)] for _ in range(M)] # escribiendo en orden row-1
    print("[*] Matriz creada")
    print("[*] Empezando a leer la matriz en orden column-major")

    for j in range(N):
        for i in range(M):
            a = matrix[i][j]

    for i in range(M):
        for j in range(N):
            a = matrix[i][j]

    