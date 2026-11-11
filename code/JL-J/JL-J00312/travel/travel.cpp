#include <iostream>
#include <cstring>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    bool type = false;
    cin >>a >> b >> c >> d;
    if(a == c){
         cout << "1";
         if(b[0] == d[0] && b[1] == d[1]){
            cout << "1";
            type = true;
         }
         else
            cout << "000";
    }
    else
        cout << "0000";
    if(type){
        if((b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' || d[2] == 'D')){
            cout << "11";
        }
        else if((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (d[2] == 'A' || d[2] == 'B' || d[2] == 'C')){
            cout << "1";
            if((b[2] == 'A' && d[2] == 'B') || (d[2] == 'A' && b[2] == 'B') || (b[2] == 'B' && d[2] == 'C') || (d[2] == 'B' && b[2] == 'C'))
                cout << "1";
            else
                cout << "0";
        }
        else
            cout << "00";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
