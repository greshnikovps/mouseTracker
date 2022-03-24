# mouseTracker
Задание:
1. Разаработать GUI-приложения на базе фрэймворка QT для анализа работы манипулятора мышь
1.2 GUI приложений реализовать на Русском языке
2. Требования к приложению:
2.1 Приложение осуществляет рассчет пути движения указателя мыши за заданный интервал времени
2.2 GUI приложения состоит из двух частей
2.2.1 Область движения мыши
2.2.2 Область отображения текущих координат и пройденного пути в pixel за заданный интервал времени
2.3 Заданный интервал времени должен загружаться/сохраняться в файле настроек приложения
2.4 Заданный интервал времени задается через отдельный диалог
2.5 Приложение сохраняет пройденный пути в pixel в файл
2.5.1 Сохранение в файл реализовать в отдельном потоке(по возможности)
2.6 Имя файла имеет вид время.txt(где время - текущая дата/время в формате UTC)
2.7 Папка с файлами пройденного пути должена загружаться/сохраняться в файле настроек клиента
2.8 Папка с файлами задается через отдельный диалог
2.9 Вызов всех диалогов происходит через главное меню приложения

Результат:
1. Исходный код приложений
2. Бинарное приложение

Инструменты:
1. MS Visual Studio 2015 и выше (можно реализовать на QtCreator 4.2 и выше)
2. QT 5.11 и выше

Описание использования программы:
Окно программы содержит красную прямоугольную область, в ней происходит отслеживание курсора. 
Рядом с красной областью отображаются координаты курсора и пройденный курсором путь в течение заданного промежутка времени.
Когда промежуток времени заканчивается, пусть обнуляется и рассчитывается заново.
