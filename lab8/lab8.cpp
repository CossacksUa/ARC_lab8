#include <iostream>
using namespace std;

int main() {
    // Масив з 11 елементів
    int arr[11] = {45, 12, 23, 89, 56, 67, 78, 34, 21, 90, 10};
    int n = 11; // Розмір масиву

    // Сортування масиву за спаданням методом вибору
    _asm {
        mov ESI, 0           ; Індекс i для зовнішнього циклу

    outer_loop:
        cmp ESI, 10          ; Якщо i >= 10, закінчуємо сортування
        jge done

        mov EBX, ESI         ; maxIdx = i
        mov EDI, ESI         ; Індекс j для внутрішнього циклу
        inc EDI              ; j = i + 1

    inner_loop:
        cmp EDI, 11          ; Якщо j >= 11, виходимо з внутрішнього циклу
        jge swap_elements

        ; Порівнюємо arr[j] з arr[maxIdx]
        mov EAX, arr[EDI*4]  ; Завантажуємо arr[j] у EAX
        cmp EAX, arr[EBX*4]  ; Порівнюємо з arr[maxIdx]
        jle no_update        ; Якщо arr[j] <= arr[maxIdx], не оновлюємо maxIdx

        mov EBX, EDI         ; Оновлюємо maxIdx

    no_update:
        inc EDI              ; j++
        jmp inner_loop       ; Повертаємося до початку внутрішнього циклу

    swap_elements:
        ; Якщо maxIdx != i, міняємо місцями arr[i] і arr[maxIdx]
        cmp EBX, ESI
        je skip_swap         ; Якщо maxIdx == i, пропускаємо обмін

        ; Обмін arr[i] і arr[maxIdx]
        mov EAX, arr[ESI*4]  ; EAX = arr[i]
        mov ECX, arr[EBX*4]  ; ECX = arr[maxIdx]
        mov arr[ESI*4], ECX  ; arr[i] = arr[maxIdx]
        mov arr[EBX*4], EAX  ; arr[maxIdx] = EAX (arr[i])

    skip_swap:
        inc ESI              ; i++
        jmp outer_loop       ; Повертаємося до початку зовнішнього циклу

    done:
    }

    // Виведення відсортованого масиву
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
