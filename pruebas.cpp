#include <iostream>

using namespace std;

string encrypted(int rows, int cols, string message){

    if (message.length() <= rows * cols){
        string messageEncrypted;

        for (int j = cols - 1; j >= 0; j--){
            for (int i = rows - 1; i >= 0; i--){
                if (message.length() > j + i * cols){
                    messageEncrypted += message[j + i * cols];
                }
                else{
                    messageEncrypted += " ";
                }
            }
        }
        return messageEncrypted;
    }
    else{
        return "";
    }
}

string decrypted(int rows, int cols, string message){
    if( rows * cols == message.length()){
        string messageDecrypted;
        for (int i = rows - 1; i >= 0; i--){
            for (int j = cols - 1; j >= 0; j--){
                messageDecrypted += message[i + j * rows];
            }
        }
        return messageDecrypted;
    }
    else{
        return "";
    }

}

int main(){

    string message;
    int rows = 0, cols = 0;

    cout << "ingrese el mensaje: ";
    getline(cin, message);
    cout << "ingrese el contraseña(rows): ";
    cin >> rows;
    cout << "ingrese el contraseña(cols): ";
    cin >> cols;
    if ( rows * cols >= message.length()){
        message = encrypted(rows, cols, message);
        cout << message << endl;
        message = decrypted(rows, cols, message);
        cout << message << endl;
    }
    else{
        cout << "No se puede encriptar";
    }
}