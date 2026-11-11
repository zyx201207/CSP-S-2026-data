#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],ans=-1,maxx=LLONG_MIN,vis[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(ans==-1) ans=a[i];
		else ans&=a[i];
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int k=1;k<=n;k++){
		int res=a[k];
		vis[k]=true;
		for(int i=2;i<=m;i++){
			int maxi=0;
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if((res&a[j])>(res&a[maxi])) maxi=j;
			}
			res&=a[maxi];
			vis[maxi]=true;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
