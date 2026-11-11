#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cx1,cx2,p1,p2,ce1,ce2;
char l1,l2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cx1=(int)(c1[0]-'0')*10+(int)(c1[1]-'0');
    cx2=(int)(c2[0]-'0')*10+(int)(c2[1]-'0');
    p1=(int)(s1[0]-'0')*10+(int)(s1[1]-'0');
    p2=(int)(s2[0]-'0')*10+(int)(s2[1]-'0');
    l1=s1[2];
    l2=s2[2];
    if(l1>='A'&&l1<='C')ce1=1;
    else ce1=0;
    if(l2>='A'&&l2<='C')ce2=1;
    else ce2=0;
    //cout<<cx1<<' '<<p1<<' '<<l1<<' '<<ce1<<endl;
    //cout<<cx2<<' '<<p2<<' '<<l2<<' '<<ce2<<endl;
    if(cx1==cx2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(p1==p2){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(ce1==ce2){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(ce1==ce2){
        if(l1>l2)swap(l1,l2);
        if((int)(l2-l1)==1)cout<<1;
        else cout<<0;
    }else{
        cout<<0;
    }
    return 0;
}
