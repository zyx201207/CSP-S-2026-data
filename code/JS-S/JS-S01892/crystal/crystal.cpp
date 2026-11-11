#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
ll a[N];
ll n,m;
ll b[N];
int ans;
inline int check(int x,bool f){
    for(register int i=1;i<=n;++i){
        if(a[i]>x)b[i]=2e12+7;
        else b[i]=x-a[i];
    }
    sort(b+1,b+1+n);
    ll s=0;
    int cnt=0;
    for(register int i=1;i<=n;++i){
        if(s+b[i]<=m){
            s+=b[i];
            cnt++;
            // if(s+b[i]>m)break;
        }else{
            break;
        }
    }
    ans=max(ans,cnt);
    return (f?cnt:s);
}
int cf[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n>>m;
    ll ma=-1e12,mi=1e12;
    for(register int i=1;i<=n;++i){
        cin >>a[i];
        ma=max(ma,a[i]);
        mi=min(mi,a[i]);
    }
    ll l=mi,r=ma;
    while(l<r){
        int mid1=(l*2+r)/3;
        int mid2=(l+r*2)/3;
        int ch1=check(mid1,1),ch2=check(mid2,1);
        if(ch1<ch2){
            l=mid1+1;
        }else if(ch1==ch2){
            int ch11=check(mid1,0),ch22=check(mid2,0);
            if(ch11>ch22)r=mid2-1;
            else l=mid1+1;
        }else{
            r=mid2-1;
        }
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 12
4 9 16 25 49
*/