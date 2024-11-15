Este es un programa sencillo que toma un texto y lo codifica. Este encoder realiza una transformación; en este caso, implementa un encoder básico en el que se convierten los caracteres en una representación numérica, 
como un one-hot encoding o un simple encoding que asigna números a cada carácter.

Aquí te muestro un ejemplo de un encoder básico que asigna un índice numérico único a cada carácter en una cadena, transformando el texto en una secuencia de números.

Explicación del Código

    Clase Encoder: La clase Encoder tiene dos métodos principales:
        encode: Toma una cadena de texto y convierte cada carácter en un número único. Los caracteres se mapean a índices mediante un unordered_map.
        decode: Convierte la representación numérica de regreso al texto original, usando otro mapa (index_to_char).

    Mapa persistente: la clase Encoder tiene dos mapas de clase:

    char_to_index: Asigna cada carácter a un índice único durante la codificación.
    index_to_char: Almacena el mapeo inverso para que podamos decodificar correctamente.

    Método decode: Al decodificar, el método usa index_to_char para convertir cada índice en el carácter original.
