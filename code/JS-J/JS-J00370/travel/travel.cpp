#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char c[15];

int x,y,n,m;
char a,b;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    for(int i=1;i<=10;i++) cin>>c[i];
    x=c[1]*10+c[2];
    y=c[3]*10+c[4];
    n=c[6]*10+c[7];
    m=c[8]*10+c[9];
    a=c[5],b=c[10];
    if(x==n){
        cout<<1;
        if(y==m){
            cout<<1;
            if((a=='E'&&b=='F')||(a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='C'&&b=='A')||(a=='B'&&b=='A')||(a=='F'&&b=='E')){
                cout<<1;
                if((a=='E'&&b=='F')||(a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='B'&&b=='A')||(a=='F'&&b=='E'))
                    cout<<1;
                else
                    cout<<"0";
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
