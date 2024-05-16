//	Библиотека для работы с адресными светодиодами WS2812B: http://iarduino.ru/shop/Expansion-payments/neopixel-trema-modul.html
//  Версия: 1.0.1
//  Последнюю версию библиотеки Вы можете скачать по ссылке: http://iarduino.ru/file/296.html
//  Подробное описание функции бибилиотеки доступно по ссылке: http://wiki.iarduino.ru/page/adresnye-svetodiody-moduli-neopixel/
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru

#ifndef iarduino_NeoPixel_h
#define iarduino_NeoPixel_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define	NeoPixelAll			 65535L																		//	Константа указывающая, что цвет применяется ко всем светодиодам
																										//
class iarduino_NeoPixel{																				//
	public:						iarduino_NeoPixel	(uint8_t, uint16_t=0);								//	Подключение		(№ вывода к которому подключены светодиоды, количество подключённых светодиодов)
					void		setColor			(uint16_t, uint8_t, uint8_t, uint8_t, uint8_t=127);	//	Указание цвета	(№ светодиода, R,G,B, яркость)
					void		setColor			(uint16_t, uint32_t, uint8_t=127);					//	Указание цвета	(№ светодиода, RGB, яркость)
					bool		begin				(void);												//	Инициализация работы со светодиодами
					void		write				(void);												//	Запись данных в светодиоды
					uint16_t	count				(void){return lenRGB? lenLED:0;}					//	Получение количества светодиодов
					uint8_t*	getPointer          (void){return lenRGB? arrRGB:0;}					//	Получение указателя на массив с цветами для светодиодов
	private:																							//
					uint8_t		pinOutput;																//	Определяем переменную для хранения номера вывода используемого как выход для подключения светодиодов.
	#if defined(ESP32)																					//
		volatile	uint32_t*	portOutput;																//	Объявляем  указатель на адрес регистра управления выводами, который управляет выводом pinOutput.
					uint32_t	pinMask;																//	Объявляем  переменную для хранения маски регистра portOutput соответствующей выводу pinOutput.
					uint32_t	bitLow;																	//	Объявляем  переменную для хранения значения, запись которого в portOutput приведёт к появлению 0 на выходе pinOutput.
					uint32_t	bitHigh;																//	Объявляем  переменную для хранения значения, запись которого в portOutput приведёт к появлению 1 на выходе pinOutput.
	#else																								//
		volatile	uint16_t*	portOutput;																//	Объявляем  указатель на адрес регистра управления выводами, который управляет выводом pinOutput.
					uint16_t	pinMask;																//	Объявляем  переменную для хранения маски регистра portOutput соответствующей выводу pinOutput.
					uint16_t	bitLow;																	//	Объявляем  переменную для хранения значения, запись которого в portOutput приведёт к появлению 0 на выходе pinOutput.
					uint16_t	bitHigh;																//	Объявляем  переменную для хранения значения, запись которого в portOutput приведёт к появлению 1 на выходе pinOutput.
	#endif																								//
					uint8_t*	arrRGB;																	//	Объявляем  указатель на массив с цветами для светодиодов.
					uint16_t	lenRGB=0;																//	Определяем количество байт в массиве с цветами светодиодов (будет равно количеству светодиодов * RGB).
					uint16_t	lenLED;																	//	Объявляем  количество свтодиодов.
};																										//

#endif