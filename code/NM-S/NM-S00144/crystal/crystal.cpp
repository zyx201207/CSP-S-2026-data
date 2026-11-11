#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
typedef long long ll;
ll n,m;
ll sum;
ll a[MAXN];
ll cf[MAXN];
int l=1,r=0;
int ans=1;
ll val;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    //freopen("crystal4.in","r",stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        cf[i]=a[i+1]-a[i];
    }

    while(l<n){
        if(r==n-1)break;
        r++;
        int len=(r-l+1);
        val+=len*cf[r];
        sum+=cf[r];
        if(val<=m)ans=max(ans,len+1);
        else{
            val-=sum;
            sum-=cf[l];
            l++;
        }
    }

    cout<<ans;
    return 0;
}