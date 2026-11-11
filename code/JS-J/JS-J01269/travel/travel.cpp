#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int a=int(s1[0]-'0')*10+int(s1[1]-'0');
    int b=int(s2[0]-'0')*10+int(s2[1]-'0');
    char c=s2[2];
    int a2=int(s3[0]-'0')*10+int(s3[1]-'0');
    int b2=int(s4[0]-'0')*10+int(s4[1]-'0');
    char c2=s4[2];
    bool n=1;
    if(a==a2){
        cout<<1;
    }
    else{
        cout<<0;
        n=0;
    }
    if(b==b2&&n==1){
        cout<<1;
    }
    else{
        cout<<0;
        n=0;
    }
    if((('A'<=c&&c<='C'&&'A'<=c2&&c2<='C')||('D'<=c&&c<='F'&&'D'<=c2&&c2<='F'))&&n==1){
        cout<<1;
    }
    else{
        cout<<0;
        n=0;
    }
    if((c2==c+1||c==c2+1)&&n==1){
       cout<<1;
    }
    else{
        cout<<0;
    }
    cout<<'\n';
    return 0;
}