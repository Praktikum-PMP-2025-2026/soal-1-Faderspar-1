/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 01
 *   Hari dan Tanggal    : Selasa, 21 April 2026
 *   Nama (NIM)          : Fauzan Akmal Rabbani (13224025)
 *   Nama File           : Soal 1
 *   Deskripsi           : Soal 1
 * 
 */
#include <stdio.h>
#include <string.h>

int main() {
    char s[1024];
    if (fgets(s, sizeof(s), stdin) == NULL) return 0;
    s[strcspn(s, "\n")] = 0;

    int n = strlen(s);
    int balance = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            balance++;
        } else if (s[i] == ')') {
            if (balance == 0) {
                s[i] = '\1'; 
            } else {
                balance--;
            }
        }
    }
    balance = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') {
            balance++;
        } else if (s[i] == '(') {
            if (s[i] != '\1') {
                if (balance == 0) {
                    s[i] = '\1';
                }
            }
        }
    }

    printf("%s\n", s);

    return 0;
}
