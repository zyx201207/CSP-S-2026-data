#include<bits/stdc++.h>
using namespace std;
string sa,sb,za,zb;
int f,ff,fff;
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>sa>>za>>sb>>zb;
    if(sa==sb){
        cout<<1;
        ff=1;
    }
    else cout<<0;
    if(ff==1&&za[0]==zb[0]&&za[1]==zb[1]){
        cout<<1;
        fff=1;
    }
    else cout<<0;
    if(fff==1&&((za[2]<='C'&&zb[2]<='C'&&za[2]>='A'&&zb[2]>='A')||(za[2]<='F'&&zb[2]<='F'&&za[2]>='D'&&zb[2]>='D'))){
        cout<<1;
        f=1;
    }
    else cout<<0;
    if(f==1&&(za[2]-zb[2]==1||zb[2]-za[2]==1)) cout<<1;
    else cout<<0;
    return 0;
}
