import speech_recognition as sr
import serial
import time

r = sr.Recognizer()

while True:
    with sr.Microphone(device_index=2) as source:
        r.adjust_for_ambient_noise(source)
        print('録音中: ')
        audio = r.listen(source)
        print('処理中')

    try:
        text = r.recognize_google(audio, language='ja-JP')

        if text in ["電源オン","電源オフ","扇風機つけて","扇風機 止めて"]:
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)           #Arduino側との接続のための待ち時間が必要
            ser.write(b'1')     #char型で送信し，Arduino側でbyte型へ変換すれば数字をそのまま扱える．
            print("sent 1")
            ser.close()

        elif text == "風量強":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'2')  
            print("sent 2")   
            ser.close()

        elif text == "風量弱":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'3')     
            print("sent 3")
            ser.close()

        elif text == "首振り":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'4')     
            ser.close()

        elif text == "ライトつけて":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'5')     
            ser.close()
        
        elif text == "ライト消して":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'6')     
            ser.close()

        elif text == "赤":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'7')     
            ser.close()

        elif text == "緑":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'8')     
            ser.close()
        
        elif text == "グラデーション":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'9')     
            ser.close()

        elif text == "白":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'a')     
            ser.close()

        elif text == "開け":
            print(text)
            ser = serial.Serial('COM6', 115200, timeout = 0.1)
            time.sleep(2)          
            ser.write(b'b')     
            ser.close()

        elif text == "終了":
            print(text)
            break

        else:
            print("{0}の指示は存在しません。".format(text))
    except:
        print("録音されていません")