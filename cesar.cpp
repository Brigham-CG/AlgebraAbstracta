#include <iostream>

using namespace std;

class cesar{

    public:

        int password = 0;

        string alfabeto = "abcdefghiojlmnñopqrtsuvwxyzABCDEFGHIJLKMNñOPQRSTUVWXYZ";

        string encrypted(string message){
            
            string messageEncrypted;

            for(int i = 0; i < message.length(); i++){

                int pos = alfabeto.find(message[i]);

                if (pos != string::npos){
                    pos += password;
                    pos %= alfabeto.length();
                    messageEncrypted += alfabeto[pos];
                    cout << pos << endl;
                }

                else{
                    messageEncrypted += message[i];
                }
            }
            return messageEncrypted;
        }

        string decrypted(string message){
            string messageDecrypted;

            for (int i = 0; i < message.length(); i++){
                
                int pos = alfabeto.find(message[i]);

                if (pos != string::npos){
                    pos -= password;
                    if (pos < 0){
                        pos * -1;
                        pos %= -1 * alfabeto.length();
                    }
                    else{
                        pos * 1;
                        pos %= alfabeto.length();
                    }
                    messageDecrypted += alfabeto[pos];
                }
                else{
                    messageDecrypted += message[i];
                }
            }
            return messageDecrypted;   
        }
};

int main(){

    cesar usuario1;
    string origin;
    cout << "Ingrese el mensaje: ";
    getline(cin, origin);
    cout << "Ingrese la contraseña: ";
    cin >> usuario1.password;

    string message = usuario1.encrypted(origin);
    cout << message << endl;
    cout << usuario1.decrypted(message) << endl;
}