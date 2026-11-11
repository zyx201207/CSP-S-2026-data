#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string che;
    string zuo;
    cin >> che >> zuo;
    int r_che,r_pai;
    int r_zuo;
    r_che = (che[0] - '0') * 10 + (che[1] - '0');
    r_pai = (zuo[0] - '0') * 10 + (zuo[1] - '0');
    r_zuo = zuo[2] - '0';
    cin >> che >> zuo;
    int x_che,x_pai;
    int x_zuo;
    x_che = (che[0] - '0') * 10 + (che[1] - '0');
    x_pai = (zuo[0] - '0') * 10 + (zuo[1] - '0');
    x_zuo = zuo[2] - '0';
    int a = 1;
    int b = 0;
    if(r_che != x_che){
        cout << b;
        cout << b;
        cout << b;
        cout << b;
    }else{
        cout << a;
        if(r_pai != x_pai){
            cout << b;
            cout << b;
            cout << b;
        }else{
            cout << a;
            if((r_zuo <= 'C' - '0' && x_zuo >= 'D' - '0') || (r_zuo >= 'D' - '0' && x_zuo <= 'C' - '0')){
                cout << b;
                cout << b;
            }else{
                cout << a;
                if(abs(r_zuo - x_zuo) == 1){
                    cout << a;
                }else{
                    if(r_zuo >= 'D' - '0'){
                        cout << a;
                    }else{
                        cout << b;
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

