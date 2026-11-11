#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;

int n;long long d;
long long x[N];
long long ans=0;


signed main(){ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,TTTT;cin>>c>>TTTT;while(TTTT--){
    ans=0;
    cin>>n>>d;
    int p0;cin>>p0;
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        x[i-1]=p-p0;
        //cout<<x[i-1]<<' ';
    }
    //cout<<'\n';
    d=(d<<1)-1;
    //qiu qu jian he = d de qu jian shu liang
    for(int l=1,r=0;;){
        while(r<=n&&x[r]-x[l-1]<d){
            ++r;
        }
        if(r>n)break;
        if(l==r)++l;
        if(x[r]-x[l-1]==d){
            //cout<<l<<' '<<r<<' '<<x[r]<<' '<<x[l-1]<<'\n';
            ++ans;
            ++l;
        }
        while(x[r]-x[l-1]>d){
            ++l;
        }
        if(l==r)++l;
        if(x[r]-x[l-1]==d){
            //cout<<l<<' '<<r<<' '<<x[r]<<' '<<x[l-1]<<'\n';
            ++ans;
            ++l;
        }
    }
    cout<<ans<<'\n';

}return 0;}
//wo jue de wo shi bian bu chu bi zhe fen geng tie ji zheng que da an de dai ma le
//bu guan le    zuo T2 qu le
//ma shang bi sai jiu jie shu le
//ting hao
