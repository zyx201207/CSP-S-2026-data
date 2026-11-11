#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
ll n,m=0,x,y,z=0,c,d=1;
ll a[N];
bool b[N][30];
string s;
ll florr(int rose,int basic){
    int leaf=0;
    while(rose){
        if(rose%2)b[basic][leaf++]=true;
        else b[basic][leaf++]=false;
        rose/=2;
    }
    for(int light=leaf;light<=29;light++){
        b[basic][light]=false;
    }
    return leaf-1;
}
ll FNF(int BF){
    ll GF=1;
    for(int Pico=1;Pico<=BF;Pico++){
        GF*=2;
    }
    return GF;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        c=max(c,florr(a[i],i));
    }
    for(int i=c;i>=0;i--){
        x=0;
        for(int j=1;j<=n;j++){
            if(b[j][i])x++;
        }
        if(x>=m){
            y=0;
            for(int j=1;j<=n;j++){
                if(b[j][i])swap(b[j],b[j-y]);
                else y++;
            }
            n-=y;
            z+=FNF(i);
        }
    }
    cout<<z;
    return 0;
}
