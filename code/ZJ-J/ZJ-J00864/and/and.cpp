#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],vis[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--){
		int tot=0;
		for(int j=1;j<=n;j++)
		   if(!vis[j]&&(a[j]&(1<<i)))tot++;
		if(tot<m)continue;
		ans+=(1<<i);
		for(int j=1;j<=n;j++)
		   if(!(a[j]&(1<<i)))vis[j]=1;
	}
	cout<<ans;
	return 0;
}