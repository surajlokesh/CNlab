#include <iostream>
#include <string.h>

using namespace std;

int crc(char *ip, char *op, char *poly, int mode)
{
    strcpy(op, ip);
    if (mode) {
        for (int i = 1; i < strlen(poly); i++)
            strcat(op, "0");
    }
    for (int i = 0; i < strlen(ip); i++) {
        if (op[i] == '1') {
            for (int j = 0; j < strlen(poly); j++) {
                if (op[i + j] == poly[j])
                    op[i + j] = '0';
                else
                    op[i + j] = '1';
            }
        }
    }
    for (int i = 0; i < strlen(op); i++)
        if (op[i] == '1')
            return 0;
    return 1;
}

int main()
{
    char ip[100], op[100], recv[100], polynomial[100];
    // char polynomial[] = "11001010";
    // char polynomial[] = "10001000000100001";

    cout << "Enter the input message in binary"<< endl;
    cin >> ip;
    cout << "Enter the polynomial generator: ";
    cin >> polynomial;
    crc(ip, op, polynomial, 1);
    cout << "The transmitted message is: " << ip << op + strlen(ip) << endl;
    cout << "Enter the recevied message in binary" << endl;
    cin >> recv;
    if (crc(recv, op, polynomial, 0))
        cout << "No error in data" << endl;
    else
        cout << "Error in data transmission has occurred" << endl;

    return 0;
}