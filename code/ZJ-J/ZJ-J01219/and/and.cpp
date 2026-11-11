#include <bits/stdc++.h>
using namespace std;
typedef long long l;
const l N=2e5+5;
l a[N],n,m,ans=-1;
l dfs(l shu,l cnt){
	if(shu==0){
		return cnt;
	}
	for(int i=1;i<=n;i++){
		if(cnt&a[i]<ans)continue;
		else ans=max(ans,dfs(shu-1,cnt&a[i]));
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cout<<dfs(m-1,0);
	return 0;
}