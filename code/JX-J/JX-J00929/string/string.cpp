#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll=long long;
const int maxn=2e5+5;
int a[maxn],n;
char c[maxn];
ll e[maxn],re[maxn];
ll ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        e[i]=e[i-1]+a[i];
    }
    for(int i=n;i>=1;--i)
        re[i]=re[i+1]+a[i];
    int nh=1,nt=n;
    for(ll i=1;i<=(e[n]>>1);){
        ll lh=e[nh]-i+1,lt=re[nt]-i+1;
        if(c[nh]==c[nt]){
            i+=min(lh,lt);
            if(lh>lt){
                nt--;
            }else if(lh==lt){
                nt--;nh++;
            }else{
                nh++;
            }
        }else{
            ans+=min(lh,lt);
            i+=min(lh,lt);
            if(lh>lt){
                nt--;
            }else if(lh==lt){
                nt--;nh++;
            }else{
                nh++;
            }
        }
    }
    cout<<ans;
}
