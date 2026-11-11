#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,a2,b1,b2,e1,e2;
char d1,d2;
bool c=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<c1.size();i++){
        a1=a1*10+c1[i]-'0';
    }
    for(int i=0;i<c2.size();i++){
        a2=a2*10+c2[i]-'0';
    }
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            b1=b1*10+s1[i]-'0';
        }
        else{
            d1=s1[i];
        }
    }
    if(d1=='D'||d1=='F')e1=1;
    else e1=2;
    for(int i=0;i<s2.size();i++){
        if(s2[i]>='0'&&s2[i]<='9'){
            b2=b2*10+s2[i]-'0';
        }
        else{
            d2=s2[i];
        }
    }
    if(d2=='D'||d2=='F')e2=1;
    else e2=2;
    if(a1==a2&&c)cout<<1;
    else{
        c=0;
        cout<<0;
    }
    if(b1==b2&&c)cout<<1;
    else{
        c=0;
        cout<<0;
    }
    if(e1==e2&&c)cout<<1;
    else{
        c=0;
        cout<<0;
    }
    if(d1=='A'&&d2=='B'||d1=='B'&&d2=='A'||d1=='B'&&d2=='C'||d1=='C'&&d2=='B'||d1=='D'&&d2=='F'||d1=='F'&&d2=='D'){
        if(c)cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
