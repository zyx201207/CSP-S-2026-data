#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    if(a!=c){
        for(int i=0;i<4;i++){
            cout << '0';
        }
        cout << endl;
        return 0;
    }
    else{
        cout << '1';
        bool f=true;
        for(int i=0;i<=1;i++){
            if(b[i]!=d[i]){
                f=false;
            }
        }
        if(!f){
            for(int i=1;i<=3;i++){
                cout << '0';
            }
            cout << endl;
            return 0;
        }
        else{
            cout << '1';
            int bs=b[2]-'A',ds=d[2]-'A';
            if(bs<=2&&ds<=2||bs>2&&ds>2){
                cout << '1';
                if(abs(bs-ds)==1||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
                    cout << '1' << endl;
                    return 0;
                }
                else{
                    cout << '0' << endl;
                    return 0;
                }
            }
            else{
                for(int i=1;i<=2;i++){
                    cout << '0';
                }
                return 0;
            }
        }
    }
    return 0;
}
