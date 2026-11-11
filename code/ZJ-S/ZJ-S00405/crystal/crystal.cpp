#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],c[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)c[i]=c[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int L=1,R=i;
        while(L<=R){
            int mid=L+R>>1;
            if(1ll*(i-mid+1)*a[i]-(c[i]-c[mid-1])<=m){
                ans=max(ans,i-mid+1);
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
    }
    cout<<ans;
    return 0;
}