#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int flag=0;
    for(int i=0;i<2;i++){
        if(a[i]==c[i]){
            flag++;
        }
    }
    if(flag==2){
        cout<<1;
    }
    else{
        cout<<0000<<endl;
        return 0;
    }
    int x=0,y=0;
    char e,f;
    for(int i=0;i<2;i++){
        if(i==1){
            x*=10;
            y*=10;
        }
        x+=b[i]-'0';
        y+=d[i]-'0';
    }
    if(x==y){
        cout<<1<<" ";
    }
    else{
        cout<<000<<endl;
        return 0;
    }
    e=b[2];
    f=d[2];
    if((e=='A'&& f=='B') || (e=='B'&& f=='C') || (e=='D'&& f=='F')){
        cout<<11<<endl;
        return 0;
    }
    else if((f=='A'&& e=='B') || (f=='B'&& e=='C') || (f=='D'&& e=='F')){
        cout<<11<<endl;
        return 0;
    }
    else if((e=='A'&& f=='C') || (f=='A'&& e=='C')){
        cout<<10<<endl;
        return 0;
    }
    else{
        cout<<00<<endl;
    }
    return 0;
}
