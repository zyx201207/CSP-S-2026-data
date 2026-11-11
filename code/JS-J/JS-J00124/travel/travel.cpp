#include<bits/stdc++.h>
using namespace std;
struct Node{
    string c,s;
};
Node a,b;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a.c>>a.s>>b.c>>b.s;
    if(a.c!=b.c){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(a.s[0]!=b.s[0]||a.s[1]!=b.s[1]){
        cout<<"000";
        return 0;
    }
    cout<<1;
    char t1=a.s[2],t2=b.s[2];
    if(t1>t2) swap(t1,t2);
    string ABC="ABC",DF="DF";
    if((ABC.find(t1)!=ABC.npos&&ABC.find(t2)!=ABC.npos)||(DF.find(t1)!=DF.npos&&DF.find(t2)!=DF.npos)) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if((t1=='A'&&t2=='B')||(t1=='B'&&t2=='C')||(t1=='D'&&t2=='F')) cout<<1;
    else cout<<0;
    return 0;
}
