#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,m;
int a[N]; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=-1e9;
    for(int i=1;i<=n;i++){
    	int k=m;
    	int tot=0;
    	for(int j=i;j>=1;j--){
    		if(a[i]-a[j]<=k){
    			k-=abs(a[i]-a[j]);tot++;
			}
		}
		ans=max(ans,tot);
	}
    cout<<ans;
	return 0;
}
