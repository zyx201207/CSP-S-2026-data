#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a[0]==c[0]&&a[1]==c[1]){
        cout << 1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout << 1;
            if(b[2]-'A'==3||b[2]-'A'==5){
                if(d[2]-'A'==3||d[2]-'A'==5){
                    cout << 1;
                    if(abs((d[2]-'A')-(b[2]-'A')==1)){
                        cout << 1;
                        return 0;
                    }else{
                        cout << 0;
                        return 0;
                    }
                }
            }else{
                if(d[2]-'A'==0||d[2]-'A'==1||d[2]-'A'==2){
                    cout << 1;
                    if(abs((d[2]-'A')-(b[2]-'A')==1)){
                        cout << 1;
                        return 0;
                    }else{
                        cout << 0;
                        return 0;
                    }
                }
            }
            cout << "00";
            return 0;
        }else{
            cout << "000";
            return 0;
        }
    }else{
        cout << "0000";
        return 0;
    }
    return 0;
}