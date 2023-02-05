import speech_recognition as sr

r = sr.Recognizer()

while True:

    with sr.Microphone(device_index=2) as source: ##index 0:内臓　1:有線 2:無線
        r.adjust_for_ambient_noise(source)
        print('録音中: ')
        audio = r.listen(source)

    try:
        text = r.recognize_google(audio, language='ja-JP')
        print(text)
    except:
        print("録音されていません")