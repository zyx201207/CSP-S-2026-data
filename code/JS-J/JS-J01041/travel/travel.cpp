#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;
    int a1=(s1[0]-'0')*10+s1[1]-'0',a2=(s2[0]-'0')*10+s2[1]-'0';
    char ch1=s1[2],ch2=s2[2];
    if(a1!=a2){
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;
    if((ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='D'||ch2=='F')||(ch2=='A'||ch2=='B'||ch2=='C')&&(ch1=='D'||ch1=='F')){
        cout<<"00"<<endl;
        return 0;
    }
    cout<<1;
    if(ch1=='A'&&ch2=='B'||ch2=='A'&&ch1=='B'||ch1=='C'&&ch2=='B'||ch2=='C'&&ch1=='B'||ch1=='D'&&ch2=='F'||ch1=='F'&&ch2=='D'){
        cout<<1<<endl;
        return 0;
    }
    cout<<0<<endl;
    return 0;
}
//100 pts
//luogu:1435076
