from fastapi import FastAPI
import encoder
import time
import json

app = FastAPI()


@app.post("/encode")
async def cc(text: str):

    start = time.time()
    
    # Crear una instancia de Encoder
    enc = encoder.Encoder()

    # Codificar un texto
    encoded_text = enc.encode(text)

    # Decodificar el texto
    decoded_text = enc.decode(encoded_text)

    end = time.time()

    var1 = end - start

    j1 = {
        "Time taken in seconds": var1,
        "Encoded text": encoded_text,
        "Decoded text": decoded_text
    }
    jj = json.dumps(j1)

    return jj