#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
bool g=1,s=0,w=0,q=0;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[1]!=c[1]){
        g=0;

        //cout<<"!!!!!!!!!!!!!!!!!!!!!";
        if((b[0]==d[0])&&b[1]==d[1]){
            s=1;
            if(((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'))||((b[2]>='D'&&b[2]<='F')&(d[2]>='D'&&d[2]<='F'))){
                w=1;
                //cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!";
                if(((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F'))||((d[2]=='A'&&b[2]=='B')||(d[2]=='B'&&b[2]=='C')||(d[2]=='D'&&b[2]=='F'))){
                    q=1;
                }
            }
        }
    }
    if(g==1&&s==1&&w==1&&q==1){
        cout<<1111;
        return  0;
    }else if(g==1&&s==1&&w==1){
        cout<<1110;
        return 0;
    }else if(g==1&&s==1){
        cout<<1100;
        return 0;
    }else if(g==1){
        cout<<1000;
        return 0;
    }else{
        cout<<"0000"<<endl;
    //cout<<g<<endl;
        //cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        return 0;
    }
    return 0;
}
