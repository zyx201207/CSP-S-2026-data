#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int ok=1;
    char x = s1[2],y = s2[2];
    if(c1==c2){
        cout << 1;
        int len = s1.size();
        for (int i = 0; i < len-1; i++){
            if(s1[i]!=s2[i]){
                ok=0;
            }
        }
        if(ok){
            cout << 1;
        } else {
            cout << 0;
        }
        if(ok){
            if(x<='C'&&y<='C'){
            cout << 1;
        } else if(x>='D'&&y>='D'){
            cout << 1;
        } else {
            cout << 0;
        }
        } else {
            cout << 0;
        }


    } else {
        cout << 0<< 0 << 0;
    }

    //cout << ok;
    if(ok){
            int flag = 1;
            if(x=='A'){
                if(y=='B'){
                    cout << 1;
                    flag=0;
                }
            }else if(x=='B'){
                if(y=='A'){
                    cout << 1;
                    flag=0;
                }
            }else if(x=='C'){
                if(y=='B'){
                    cout << 1;
                    flag = 0;
                }
            }else if(x=='B'){
                if(y=='C'){
                    cout << 1;
                    flag = 0;
                }
            }else if(x=='D'){
                if(y=='F'){
                    cout << 1;
                    flag = 0;
                }
            } else if(x=='F'){
                if(y=='D'){
                    cout << 1;
                    flag = 0;
                }
            }
            if(flag){
                cout << 0;
            }
    } else {
        cout << 0;
    }

    return 0;
}
