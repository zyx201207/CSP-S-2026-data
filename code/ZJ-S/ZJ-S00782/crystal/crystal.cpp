#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,j=1,cur;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i>1) cur-=a[j]-a[i-1];
		while(j<n&&cur<m){
			j++,cur+=(a[j]-a[j-1])*(j-i);
		}ans=max(ans,j-i);
	}cout<<ans;
}
