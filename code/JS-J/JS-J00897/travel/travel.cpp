#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
bool t=0;
void tche(){
    if(c1==c2)cout<<1;
    else{
        t=1;
        cout<<0;
    }
}
void tpai(){
    if(t==1){
        cout<<0;
        return;
    }
    char o1,o2,o3,o4;
    o1=s1[0];
    o2=s1[1];
    o3=s2[0];
    o4=s2[1];
    if(o1==o3&&o2==o4)cout<<1;
    else{
        t=1;
        cout<<0;
    }
}
void tbian(){
    char o1,o2;
    if(t==1){
        cout<<0;
    }else{
        o1=s1[2];
        o2=s2[2];
        if(o1=='A'||o1=='B'||o1=='C')a=1;
        else a=2;
        if(o2=='A'||o2=='B'||o2=='C')b=1;
        else b=2;
        if(a==b)cout<<1;
        else{
            t=1;
            cout<<0;
        }
    }
    if(t==1){
        cout<<0;
        return;
    }
    if(a==2)cout<<1;
    else{
        if(o1=='A'&&o2=='C'||o2=='A'&&o1=='C')cout<<0;
        else cout<<1;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    tche();
    tpai();
    tbian();
    return 0;
}
