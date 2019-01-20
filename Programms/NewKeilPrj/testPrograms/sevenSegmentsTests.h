#define clearScreenValue 255 //0b11111111
#define segmentOneNumber 159 //0b10011111
#define segmentTwoNumber 37 //0b00100101
#define segmentThreeNumber 13 //0b00001101
#define segmentFourNumber 153 //0b10011001
// Define another numbers by yourself


// Public

/**
 * Инициализирует сегментный индикатор
 * @note PD11 - Clock, PD12 - Data
 */
void initSegmentIndicator(void);

/**
 * Очищает сегментный индикатор
 */
void clear(void);

/**
 * Записыват в индикатор последние 8 бит переданного числа
 * @param data - число для записи в индикатор
 * @note См. примеры чисел выше.
 */
void writeTo7SegmentIndicator(int data);

/**
 * Задержка в тактах
 * @param ticks - кол-во тактов.
 */
void delay(int ticks);


// Private
void passZeroToSevenSegment(void);
void clockForSevenSegment(void);
void passOneToSevenSegment(void);

/*
 * Main example.
 */
//int main(void) {
//	initSegmentIndicator();
//	clear();
//	writeTo7SegmentIndicator(segmentOneNumber);
//	writeTo7SegmentIndicator(segmentTwoNumber);
//	writeTo7SegmentIndicator(segmentThreeNumber);
//	writeTo7SegmentIndicator(segmentFourNumber);
//
//}
