#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,d,e;
    char c1,f1;
    cin>>a>>b>>c1>>d>>e>>f1;
    if(a==d){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(b==e)
        cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((c1<='C'&&f1<='C')||(c1>'C'&&f1>'C'))
              cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if((c1=='A'&&f1=='C')||(c1=='C'&&f1=='A'))cout<<0;
    else cout<<1;
}
