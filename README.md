# Реализация стуктуры Даты с помощью наследования от класса тройки чисел

## Как установить & пользоваться
  Подробная инструкция описана в [этом файле](INSTALLATION.md)
  
## Задача, которая решалась в проекте
  ![image](https://user-images.githubusercontent.com/68380831/147282957-824ce6d8-2b3c-4dc8-bbf3-f9e70f32b343.png)
  
## Идея решения
   Проектирование классов:
   
   - Date - класс, реализующий структуру Даты
    
   - Triad - класс, реализующий структуру Тройки чисел
  
## Нюансы
   - [header.h](date-triad/header.h) - (***ВАЖНО ПОМНИТЬ***) заголовочный файл, в котором
    подключаются все библиотеки, объявляются константы и используется `using` в качестве современной замены `typedef`.
    
   - [date.h](date-triad/date.h) - заголовочный файл, в котором объявлен класс и его методы, представляющий структуру Даты
    
   - [date.cpp](date-triad/date.cpp) - компилируемый файл, в котором реализован методы класса `date.h`, объявленные в заголовочном файле
    
   - [triad.h](date-triad/triad.h) - заголовочный файл, в котором объявлен класс и его методы, представляющий структуру Тройки чисел
    
   - [triad.cpp](date-triad/triad.cpp) - компилируемый файл, в котором реализован методы класса `triad.h`, объявленные в заголовочном файле
    
   - В задаче присутсвует использование `tuple<тип,тип,тип>` . Берётся этот `tuple` из стандартной библиотеки `<tuple>`. Эти тюплы позволяют
  создавать набор из N разно-типных _(или одинаковых)_ данных (кортеж). Так, мы можем хранить 3 `int'a` и 2 `double'a` :
```c++ 
      tuple<int,int,int,double,double>
``` 

 или же, как они и используются, возвращать с помощью них сразу три числа `tuple<size_t,size_t,size_t>` 

 - Для получения данных из `tuple'a` нужно пользоваться методом `get` :
```c++
   get<позиция>(наш тюпл)
```
- Строчка:
```c++
   using triple_t = tuple<size_t, size_t, size_t>;
```
  Равносильна строчке: 
```c++
   typedef tuple<size_t, size_t, size_t> triple_t;
```

 - Класс Date был взят [отсюда](https://github.com/Sanlovty/lab-date), доккументацию к нему можно найти [тут](https://github.com/Sanlovty/lab-date/tree/comments)

## Автор
  **Глеб Первеев** - [Sanlovty](https://github.com/Sanlovty)

## Лицензия

Этот проект находится под лицензией Apache License 2.0 - подробности см. в файле [LICENSE](LICENSE)
