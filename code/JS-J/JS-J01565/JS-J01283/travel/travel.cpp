#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int num1=b[2]-'A';
    int num2=d[2]-'A';
    if(a==c){
        if(b[0]==d[0]&&b[1]==d[1]){
            if((num1<=2&&num2<=2) || (num1>=2&&num1<=4&&num2>=2&&num2<=4)){
                if(abs(num1-num2)==1){
                    cout<<1111;
                    return 0;
                }
                cout<<1110;
                return 0;
            }
            cout <<1100;
            return 0;
        }
        cout<<1000;
        return 0;
    }
    cout<<0000;
    return 0;
}
