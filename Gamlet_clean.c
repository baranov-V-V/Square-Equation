#include "Gamlet_header.h"

int main(int argc,char* argv[]) {

    if (argc > 1) {

        int i = 1;
        for (i; i < argc; i++) {
            if (argv[i] == "--debug") {
                Test_All();
            }
            else {
                fprintf(stderr,"Unknown command : %s", argv[i]);
            }
        }
    }

    //-------------------------------------
    //    Считываем текст из файла
    //-------------------------------------
    char* file_in = "Gamlet_parsed.txt";
    char* file_out = "Gamlet_test_for_clean.txt";

    int text_size = 0;
    char* text = Get_Text(file_in, text, &text_size);

    //----------------------------------------------------------
    //  Форматируем текс и находим кол-во строк
    //----------------------------------------------------------
    Change_Char(text, text_size, '\n', '\0');
    size_t lines_count = Get_Lines_Count(text, text_size);

    //-------------------------------------------------------------
    //   Создаем массив указателей на строки текста
    //-------------------------------------------------------------
    char** line_pointers = (char**) calloc((lines_count), sizeof(char*));
    Make_Line_pointers(line_pointers, text, text_size);

    //---------------------------------------------------------------------
    //   Сортируем, сравнивая с начала, и выводим в файл
    //---------------------------------------------------------------------
    Sort_Write( line_pointers, lines_count, 'n', file_out, "w");

    //---------------------------------------------------------------------
    //     Сортируем, сравнивая с конца, и выводим в файл
    //---------------------------------------------------------------------
    Sort_Write( line_pointers, lines_count, 'r', file_out, "a");

    //---------------------------------------------------------------------------------
    //     Форматируем текст, и выводим начальный вариант в файл
    //---------------------------------------------------------------------------------
    Change_Char(text, text_size, '\0', '\n');
    Write_Text(text, text_size, file_out, "a");

    //------------------------------
    //  Освобождаем память
    //------------------------------
    //free(text);
    //free(line_pointers);
    FreeALL(text, line_pointers);
    return 0;
}
