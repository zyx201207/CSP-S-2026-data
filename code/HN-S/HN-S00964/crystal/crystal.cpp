#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,a[N],ans,l=1,sum,k;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum+=(a[i]-a[i-1])*(i-l);
        while(sum>k){
            sum-=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}   