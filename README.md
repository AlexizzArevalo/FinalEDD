# Examen final EDD

# INSERTAR ELEMENTO
    
    insertame(int valor);
    
# BUSCAR ELEMENTO
  Devuelve `true` o `false`
  
    buscar(int valor);
    
    
# GRAFICAR VECTOR

    graficarvector();

# GRAFICAR AVL
El arbol AVL es graficado a partir del vector unidimensional donde:
  La raiz es el primer elemento del vector.
  El hijo izquierdo esta en la posicion `izquierdo = i*2+1`
  El hijo derecho esta en la posicion `derecho = i*2+2`
  donde `i` es la posicion del nodo actual.
    
    graficarAVL();
    
 # RECORRIDO INORDEN
 El recorrido inorden se realiza en el vector tomando como referencia el hijo izquierdo `i*2+1` y el hijo derecho `i*2+2`
    
    preOrden(raiz);
    
  # GRAFICAS
  Las graficas de ejemplo se encuentran en la raiz del proyecto.
  
  `ArbolAVL.png` y `Vector.png`
