#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll m,a[N],b[N];
int n;
bool check(int x){
    for(int i=1;i<=n-x+1;i++){
        ll sum=b[i+x-1]-b[i-1],sum2=a[i+x-1]*x;
        //cout<<x<<" "<<sum<<" "<<sum2<<endl;
        if(sum2-sum<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    int l=0,r=n,ans;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ans;
    return 0;
}
