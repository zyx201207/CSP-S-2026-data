#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,l,r,ans,arr[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+arr[i];
    l=1,r=1;
    while(r<n){
        while((arr[r]*(r-l+1)-(pre[r]-pre[l-1])<=m)&&r<n)r++;
        if(arr[r]*(r-l+1)-(pre[r]-pre[l-1])>m)r--;
        ans=max(ans,r-l+1);
        l++;
    }
    cout<<ans;
    return 0;
}
