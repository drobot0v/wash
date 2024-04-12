import serial.tools.list_ports as lp
import serial
import time

ports = lp.comports()
for port in ports:
    print(f"Port: {port.name}")


def connect(port='COM3', baudrate=9600, 
            read_timeout=2, write_timeout=8):
    ser = serial.Serial(port=port, baudrate=baudrate, 
                         timeout=read_timeout, write_timeout=write_timeout
                         # ,
                         # bytesize=8, 
                         # stopbits=serial.STOPBITS_ONE,
                         # xonxoff=False
                         )
    time.sleep(1.8)
    return ser


def exchange_data(input, 
                  connection=connect(read_timeout=10), close_connection=True):
    request = str(input)
    # request += '\n'
    print(request)

    # connection.write(request.encode(encoding='ascii', errors='strict'))
    connection.write(request.encode(encoding='ascii'))
    response = b''
    try:
        # response = connection.read_until(b'\n')
        response = connection.readline()
        print(response)
    except:
         pass
    if close_connection:
                connection.close()
    return {'Connection': connection, 
                    'Response': response, 'Decoded': response.decode()}
    

res = exchange_data("Hi")
print(res)
