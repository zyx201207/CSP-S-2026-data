#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,n=0,m=0,x,y;
    string s1,s2,v,t;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
        cout<<"0000"<<endl;
        return 0;
    }
    for(int i=0;i<=1;i++){
        n+=s1[i]*pow(10,1-i);
        m+=s2[i]*pow(10,1-i);
    }
    if(n==m)cout<<1;
    else{
        cout<<"000"<<endl;
    }
    v[0]=s1[2];
    t[0]=s2[2];
    if(v[0]=='A')x=1;
    if(v[0]=='B')x=2;
    if(v[0]=='C')x=3;
    if(v[0]=='D')x=4;
    if(v[0]=='E')x=5;

    if(t[0]=='A')y=1;
    if(t[0]=='B')y=2;
    if(t[0]=='C')y=3;
    if(t[0]=='D')y=4;
    if(t[0]=='E')y=5;
    if((x<=3&&y<=3)||(x>=4&&y>=4)){
        cout<<1;
    }
    else{
        cout<<"00"<<endl;
        return 0;
    }
    if(abs(x-y)==1){
        cout<<1;
    }
    else{
        cout<<"0"<<endl;
    }
    return 0;
}




