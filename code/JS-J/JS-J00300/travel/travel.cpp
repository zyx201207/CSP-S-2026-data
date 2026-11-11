#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a,b,d,e;
    char c,f;
    cin >> a >> b >> c >> d >> e >> f;
    if(a==d){
        cout << "1";
        if(b==e){
            cout << "1";
            if(((c<='C'&&c>='A')&&(f<='C'&&f>='A'))||((c=='F'||c=='D')&&(f<='F'&&f>='D'))){
                cout << "1";
                if(max(c,f)-1==min(c,f)){
                    cout << "1";
                }else{
                    cout << "0";
                }
            }else{
                cout << "00";
            }
        }else{
            cout <<"000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}
