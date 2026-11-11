#include<bits/stdc++.h>
using namespace std;
int x[1000],m[100];
string a,b,y;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopon("travel.in","r",stdin);
    freopon("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        cin>>a;
        x[i]+=(int(a[0])-48)*10;
        x[i]+=int(a[1])-48;
        cin>>b;
        m[i]+=(int(b[0])-48)*10;
        m[i]+=int(b[1])-48;
        y[i]=b[2];
    }
    if(x[1]==x[2]){
        if(m[1]==m[2]){
            if(int(y[1])<='C' and int(y[2])<='C' or int(y[1])>'C' and int(y[2])>'C'){
                if(int(y[1])-int(y[2])==1 or int(y[2])-int(y[1])==1){
                    cout<<1111;
                }else{
                    cout<<1110;
                }
            }else{
                cout<<1100;
            }
        }else{
            cout<<1000;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
