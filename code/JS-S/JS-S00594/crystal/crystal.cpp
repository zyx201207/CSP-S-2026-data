#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn=5e5+7;
int n,m;
int a[maxn];
int last_num,last_val,last_l,ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    last_num=1;last_l=1;last_val=0;ans=1;
    for(int i=2;i<=n;i++){
        last_val+=(a[i]-a[i-1])*last_num;last_num++;
        while(last_val>m){
            last_val-=a[i]-a[last_l++];
            last_num--;
        }
        ans=max(ans,last_num);
    }
    cout<<ans<<'\n';
}