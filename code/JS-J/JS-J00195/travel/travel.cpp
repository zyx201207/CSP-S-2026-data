#include<bits/stdc++.h>
using namespace std;
string a1;
string a2;
int a,b;
bool check(int m,int n){
    if((m<=2&&n<=2)||(m>=3&&n>=3))
        return 1;
    return 0;
}
int abs(int a){
    if(a>=0)return a;
    else return -a;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a>>a1>>b>>a2;
    if(a==b)cout<<1;
    else{
        cout<<"0000"<<endl;
        return 0;
    }
    if(a1[0]==a2[0]&&a1[1]==a2[1])cout<<1;
    else{
        cout<<"000"<<endl;
        return 0;
    }
    int r=a1[2]-'A';
    int q=a2[2]-'A';
    if(check(r,q))
        cout<<1;
    else{
        cout<<"00"<<endl;
        return 0;
    }
    if(abs(r-q)==1)cout<<1<<endl;
    else{
        cout<<0<<endl;
        return 0;
    }


    return 0;
}
