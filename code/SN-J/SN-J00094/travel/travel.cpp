#include<bits/stdc++.h>

using namespace std;

int ab[255];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    ab['A']=1;
    ab['B']=1;
    ab['C']=1;
    ab['D']=0;
    ab['F']=0;
    if(a == c){
        cout << 1;
        if(b[0] == d[0]&&b[1] == d[1]){
            cout << 1;
            if(ab[b[2]] == ab[d[2]]){
                cout << 1;
                if((b[2] == 'C'&&d[2] == 'A')||(b[2] == 'A'&&d[2] == 'C')){
                    cout << 0;
                }else{
                    cout << 1;
                }
            }else{
                cout << 0 << 0;
            }
        }else{
            cout << 0 << 0 << 0;
        }
    }else{
        cout << 0 << 0 << 0 << 0;
    }

    return 0;
}
