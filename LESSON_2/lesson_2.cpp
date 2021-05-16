#include <iostream>
#include <cstdlib>
#include <cstring>
#include <bitset>


int main(int argc, char const *argv[]) {
    // 1. Создать и инициализировать переменные пройденных типов данных
	int i = 1;
    float f = 1.23456;
    double d = 1.234567;
    bool b = true; // or could be "false"
	printf("Int i = %d, float f = %f, double d = %f, bool b = %d \r\n", i, f, d, b);
    char letterA;
    letterA = 'A';
    char letterH = 72;
    std::cout << "Char LetterH:" << letterH << ", Char LetterA:" << letterA << std::endl;

	const double pi = 3.1415926;
   
    // 2. Создать перечисление с возможными вариантами символов для игры в крестики-нолики
    enum tic_tac_toe {X, O, empty};
    using ttt = enum tic_tac_toe;
   
    // 3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
    ttt array[3][3]= {
        {X,     X,      O},
        {empty, X,      O},
        {X,     O,  empty}
    };
   
    // 4. * Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми (на Ваш взгляд) свойствами
    enum ttt_players {player1, player2}; //Перечисление игроков для отслеживания ходов
    struct ttt_board {
        ttt board[3][3] = {
            {empty, empty, empty},
            {empty, empty, empty},
            {empty, empty, empty}
        };
        ttt_players first_turn; // Сохраняем кто ходит первый
        ttt_players current_turn; // Сохраняем чей сейчас ход
    } new_board;
    
    // 5. ** Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении
    struct ext_union {
        union un {
            int in;
            double fl;
            char ch;
        } un;  
        int is_int:1;
        int is_double:1;
        int is_char:1;
    } ext_un;

    ext_un.un.in = 5;
    ext_un.is_int = 1;
    ext_un.is_double = 0;
    ext_un.is_char = 0;

    std::cout << "un.in " << ext_un.un.in << std::endl;
    std::cout << "un.ch " << ext_un.un.ch << std::endl;
    std::cout << "un.fl " << ext_un.un.fl << std::endl;
    std::cout << "is_int " << ext_un.is_int << std::endl;
    std::cout << "is_double " << ext_un.is_double << std::endl;
    std::cout << "is_char " << ext_un.is_char << std::endl;
    std::cout << "is_int bitset " << std::bitset<1>(ext_un.is_int) << std::endl;
    std::cout << "is_double bitset " << std::bitset<1>(ext_un.is_double) << std::endl;
    std::cout << "is_char bitset " << std::bitset<1>(ext_un.is_char) << std::endl;
	return 0;
}

/* Program ./lesson_2 output:
Int i = 1, float f = 1.234560, double d = 1.234567, bool b = 1 
Char LetterH:H, Char LetterA:A
un.in 5
un.ch 
un.fl 2.47033e-323
is_int -1
is_double 0
is_char 0
is_int bitset 1
is_double bitset 0
is_char bitset 0
*/