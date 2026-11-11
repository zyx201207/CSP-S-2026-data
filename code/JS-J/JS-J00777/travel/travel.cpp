#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        string s,ss;
        s=b[0]+b[1];
        ss=d[0]+d[1];
        char n=b[2];
        char m=d[2];
        if(ss==s){
            if(n>='A'&&n<='C'&&m>='A'&&m<='C'){
                if(n+1==m||m+1==n){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else if(n>='D'&&n<='E'&&m>='D'&&m<='E'){
                    cout<<"1111";
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
