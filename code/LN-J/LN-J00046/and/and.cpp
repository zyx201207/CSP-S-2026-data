#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int n,a[200005],m,b[200005];
void dfs(int x,int y){
	if(y==m+1){
		long long ssum=a[b[m]];
		for(int i=m-1;i>=1;i--){
			ssum&=a[b[i]];
			if(ssum<=ans)return;
		}
		ans=max(ans,ssum);
		return;
	}
	for(int i=x;i<=n;i++){
		b[y]=i;
		dfs(i+1,y+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(1,1);
	cout<<ans;
	return 0;
}
