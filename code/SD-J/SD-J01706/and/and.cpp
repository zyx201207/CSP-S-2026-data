#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],vis[200001],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=30;j>=0;j--){
		int b=(1<<j),cnt=0;
		for(int i=1;i<=n;i++)if(!vis[i]&&(a[i]&b))cnt++;
		if(cnt>=m){
			ans|=b;
			for(int i=1;i<=n;i++)if(!(a[i]&b))vis[i]|=1;
		}
	}
	cout<<ans;
	return 0;
}

