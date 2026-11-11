#include<bits/stdc++.h>
using namespace std;

int a,b,c,d;
char ch1,ch2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>ch1>>c>>d>>ch2;
    if(a==c){
        cout<<1;
        if(b==d){
            cout<<1;
            if((ch1>'C')==(ch2>'C')){
                cout<<1;
                cout<<(abs(ch1-ch2)==1);
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
