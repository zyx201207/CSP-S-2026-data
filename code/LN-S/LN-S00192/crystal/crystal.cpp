

#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;
ll n,m;
ll a[maxn];
ll sum[maxn];
ll w;
ll len;
ll ans=0;
int main(){
    freopen("crystal.in","r",stdin);//要检查
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        sum[i]=a[i]-a[i-1];
    }
    ll i=1,j=1;
    len=0;
    w=0;
    while(j<=n){
        if(w<=m){
            ans=max(ans,len);
            w+=len*sum[j];
            j++;
            len++;
        }
        else{
            len--;
            w-=(a[j]-a[i]);
            i++;
            //弹出左端//剪掉当前的能量增加值
        }
    }
    cout<<ans;
    return 0;
}//排序，求相邻差
//容量相差的
//维护一个单调队列
//每次记录当前长度并对前面的一起累加

