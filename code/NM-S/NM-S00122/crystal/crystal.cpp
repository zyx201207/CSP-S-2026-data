#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+50;
ll a[N],n,m,pre[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    if(n==1){
    	cout<<1;
    	return 0;
	}
    if(a[2]-a[1]<=m) ans=2;
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]>m) continue;
        ll l=1,r=i-1;
        while(l<r){
            ll mid=(l+r)>>1;
            ll g=(i-mid)*a[i]-(pre[i-1]-pre[mid-1]);
            if(g<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
