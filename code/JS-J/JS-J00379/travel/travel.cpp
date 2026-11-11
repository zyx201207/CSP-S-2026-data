#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char e,f;
    cin>>a>>b>>e>>c>>d>>f;
    if(a==c) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(b==d) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(((e<='C'&&f<='C')||(e>='D'&&f>='D'))) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(abs((int)e-(int)f)==1){
        if((e=='C'&&f=='D')||(e=='D'&&f=='C')) cout<<0;
        else cout<<1;
    }else cout<<0;
	return 0;
}
/*
I often recall about the past.
*/
