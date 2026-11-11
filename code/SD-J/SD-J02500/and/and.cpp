#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[200010],ans=-1,step[200010];

void dfs(int num,int now,int tot){
	if(tot==m){
		ans=max(ans,now&a[num]);
//		cout<<ans<<' ';
		return;
	}
	
	now&=a[num];
//	cout<<now<<endl;
	
	for(int i=1;i<=n;i++){
		if(step[i])continue;
		
		step[i]=1;
		dfs(i,now,tot+1);
		step[i]=0;
	}
	
	
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=2147483647;
	
	dfs(0,2147483647,0);
	
	cout<<ans;

	return 0;
}

