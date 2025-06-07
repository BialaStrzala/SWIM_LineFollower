# 🚗 Autonomiczny Pojazd z STM32

- Projekt semestralny z przedmiotu **Systemy Wbudowane i Mikrokontrolery**  
- Autor: Paula Grzebyk
- Numer indeksu: 21236
- Data rozpoczęcia: 7 maja 2025
- Data zakończenia: 3 czerwca 2025
- Repozytorium zawiera kod, dokumentację oraz materiały projektowe.

---

## 📌 Opis projektu

Robot trójkołowy o wymiarach ok. 24x20x15cm o napędzie kołowym za pomocą dwóch silników DC 5V, sterowany przez mikrokontroler STM32F051R8T6. Realizacja skrętu to obrót jednego koła według wskazówek zegara, a drugiego odwrotnie. Robot jest zasilany z koszyka na dwa ogniwa Li-On 18650 (łącznie 7,4V). Dodatkowo robot jest wyposażony w moduł Bluetooth HC-06 do komunikacji i sterowania z komputera za pomocą UART.

---

## 🛠️ Zastosowane technologie i narzędzia

- **Mikrokontroler:** STM32F051R8T6
- **IDE:** STM32CubeIDE
- **Programowanie:** C (HAL)
- **Sensory:** 5 czujników IR
- **Zasilanie:** Dwa ogniwa 18650
- **Sterownik silników:** L298N
- **Komunikacja:** UART (Bluetooth HC-06)

---

## 🛠️ Lista wszystkich elementów
- STM32F051R8T6
- L298N - dwukanałowy sterownik silników - moduł 12V/2A
- 2x Silnik DC 5V z oponą 65x26mm
- Kółko obrotowe
- Przetwornica step-down LM2596 3,2V-35V 3A z wyświetlaczem
- Moduł Bluetooth HC-06 ZS-040
- Koszyk na dwa ogniwa Li-On 18650
- Listwa 5 czujników IR
- Przewody

---

## ⚙️ Funkcjonalności

- ✅ Odczyt wartości z sensorów IR i podążanie za linią
- ✅ Sterowanie ruchem przez Bluetooth i UART (W/S/A/D)
- ✅ Zasilanie bateryjne – pełna autonomia

---

## 📸 Demo i zdjęcia

Nagrania i zdjęcia: [Folder]([#](https://drive.google.com/drive/folders/1Ak4zJQ64U5y1St-GSTiknMUM3oySruRG?usp=sharing))

---

## 📄 Dokumentacja

Pełna dokumentacja projektu znajduje się w folderze [`docs/`](./docs/), w tym:
- Raport końcowy (PDF)
- Schematy układów
- Lista komponentów

---

## 📅 Harmonogram pracy

- 7.05.2025 - rozpoczęcie prac
- 20.05.2025 – ukończenie budowy pojazdu i zaprogramowanie prostej sekwencji jazdy
- 27.05.2025 – ukończenie programowania podążania za linią
- 03.06.2025 – dodatkowa funkcjonalność: sterowanie przez bluetooth
- 10.06.2025 - finalna prezentacja

---

## 📬 Kontakt

W razie pytań:
- Email: paulagrzebyk@gmail.com
- GitHub: [BialaStrzala](https://github.com/BialaStrzala)

---

**Licencja:** MIT  
