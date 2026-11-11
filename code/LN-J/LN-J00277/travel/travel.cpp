#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=0,y=0;
    x=(a[0]-'0')*10+(a[1]-'0');
    y=(c[0]-'0')*10+(c[1]-'0');
    if(x==y){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            int f1=0,f2=0;
            if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
                f1=1;
            }
            if(b[2]=='D'||b[2]=='F'){
                f1=2;
            }
            if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
                f2=1;
            }
            if(d[2]=='D'||d[2]=='F'){
                f2=2;
            }
            if(f1==f2){
                cout<<1;
                int n=0,m=0;
                n=b[2]-64;
                m=d[2]-64;
                if(n==6)n--;
                if(m==6)m--;
                if(n-m==1||m-n==1){
                    cout<<1;
                }else{
                    cout<<0;
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
