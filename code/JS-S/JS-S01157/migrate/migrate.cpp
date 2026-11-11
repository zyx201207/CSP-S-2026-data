#include<bits/stdc++.h>
#define ll long long
#define atn 2222222
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
ll a[atn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,T;
    cin>>c>>T;
    while(T--){
        ll n,d;
        cin>>n>>d;
        if(c==11||c==12){
            f(i,1,n)cin>>a[i];
            //cout<<n<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<d<<'\n';
            if(n==1)cout<<0<<'\n';
            else{
                if(d!=d/(a[2]-a[1])*(a[2]-a[1]))cout<<0<<'\n';
                else cout<<n-(d/(a[2]-a[1]))<<'\n';
            }
            continue;
        }
        int ans=0;
        f(i,1,n)cin>>a[i];
        f(i,1,n){
            f(j,i+3,n){
                int mn=0x3f3f3f3f,wy=0;
                f(msk,0,(1<<(j-i-1))){
                    vector<int>v;
                    v.pb(i);
                    f(k,i+1,j-1)if(msk&(1<<(k-i-1)))v.pb(k);
                    v.pb(j);
                    bool f=1;
                    f(k,1,(int)v.size()-1){
                        if(a[v[k]]-a[v[k-1]]>d){
                            f=0;break;
                        }
                    }
                    if(f){
                        int tt=__builtin_popcount(msk);
                        if(mn>tt)mn=tt,wy=1;
                        else if(mn==tt)wy++;
                    }
                }
                if(wy==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
