#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[1]==c[1]){
        cout<<1;
        if(b[1]==d[1]){
            cout<<1;
            if(b[2]>='D'&&d[2]>='D'){
                cout<<1<<1;
            }
            else if(b[2]<='C'&&d[2]<='C'){
                cout<<1;
                if(int(b[2])-int(d[2])==1||int(b[2])-int(d[2])==-1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
