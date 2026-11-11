#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans,vis[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=31;i>=0;i--){
		int p=1<<i,s=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				if(a[j]&p)s++;
			}
		}
		if(s<m)continue;
		ans+=p;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				if(!(a[j]&p)){
					vis[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}