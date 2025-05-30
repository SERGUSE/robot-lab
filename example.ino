#include <RobotFunctions.h>

// Инициализация объекта робота с указанием всех пинов
RobotFunctions robot(
    4, 5, 7, 6,    // l_dir, L_speed, r_dir, R_speed
    A1, A2, 11,     // L_line, R_line, BUZZER_PIN
    2, 8,           // left_phase_a, left_phase_b
    3, 10,          // right_phase_a, right_phase_b
    800, 618        // gray_l, gray_r (значения для датчиков линии)
);

void setup() {
    Serial.begin(9600); // Инициализация Serial для отладки
    robot.playMelody(); // Проиграть мелодию при старте
    delay(1000);        // Пауза 1 сек после старта
}

void loop() {
    // 1. Проезжаем 2 перекрёстка
    Serial.println("Проезжаем 2 перекрёстка...");
    robot.go_to(2); // Метод автоматически остановится после 2 перекрёстков
    delay(500);     // Короткая пауза
    
    // 2. Поворачиваем направо на 90 градусов
    Serial.println("Поворачиваем направо...");
    robot.turn_r_n_grad(90); // Поворот на 90 градусов
    delay(500);              // Пауза после поворота
    
    // 3. Проезжаем ещё 1 перекрёсток
    Serial.println("Проезжаем 1 перекрёсток...");
    robot.go_to(1); // Проезд 1 перекрёстка
    delay(500);
    
    // 4. Сигнализируем об окончании маршрута
    Serial.println("Маршрут завершён!");
    robot.playMelody(); // Проигрываем мелодию
    
    // 5. Останавливаем программу (или можно добавить другие действия)
    robot.stopp();
    exit(0);
}
