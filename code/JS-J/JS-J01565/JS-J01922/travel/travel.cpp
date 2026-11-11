#include<bits/stdc++.h>
using namespace std;
#define gg long long

int c1,c2;
char ch;
int s1,ch1,s2,ch2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c1;
    cin>>ch;
    s1=ch-'0';
    cin>>ch;
    s1=s1*10+(ch-'0');
    cin>>ch;
    ch1=ch;

    cin>>c2;
    cin>>ch;
    s2=ch-'0';
    cin>>ch;
    s2=s2*10+(ch-'0');
    cin>>ch;
    ch2=ch;
    if(c1==c2){
        cout<<"1";
        if(s1==s2){
            cout<<"1";
            if((ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C') || (ch1>='D'&&ch1<='F'&&ch2>='D'&&ch2<='F')){
                cout<<"1";
                if((ch1>='A'&&ch1<='C'&&abs( (int)ch1-(int)ch2 ) <=1 ) || (ch2>='D'&&ch2<='F') ){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}