#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll=long long;
const int MAXN=5e5+5;
ll n,ans;
ll m,a[MAXN];
__int128 s[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll dx=a[2]-a[1];


    bool flag=true;
    for(int i=3;i<=n;++i){
        if(a[i]-a[i-1]!=dx){
            flag=false;
        }
    }
    if(flag){
        m/=dx;
        ll g;
        for(g=1;;++g){
            if((g*(g-1)>>1)>m){
                --g;break;
            }
        }
        cout<<min(n,g)<<'\n';
        return 0;
    }
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    for(int len=n;len>=1;--len){
        __int128 sum=s[len]+m;
        for(int l=1,r=l+len-1;r<=n;++l,++r){
            if(sum%len==0&&sum/len>=a[r]){
                cout<<len<<'\n';
                return 0;
            }
        sum+=a[r+1]-a[l];
        }
    }
}
