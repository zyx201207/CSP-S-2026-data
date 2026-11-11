#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],p[40],ans,vis[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=30;i++) p[i]=p[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=30;j>=0;j--){
		int sum=0;
		for(int i=1;i<=n;i++){
			if((a[i]&p[j])&&!vis[i]) sum++;
		}
		if(sum>=m){
			for(int i=1;i<=n;i++){
				if((a[i]&p[j])==0) vis[i]=1;
			}
			ans+=p[j];
		}
	}
	cout<<ans;
	return 0;
}
