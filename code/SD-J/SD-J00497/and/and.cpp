#include<bits/stdc++.h>

#define int long long

using namespace std;

int n,m;
int a[200005];
int vis[200005];
int ans;

bool cmp(int a,int b){
	return a>b;
}

bool to_two(int x){
	int cnt=0,cnt2=0;
	while(x){
		if(x%2==1)cnt++;
		x/=2;
		cnt2++;
	}
	return cnt==cnt2;
}

void dfs(int i,int sum,int cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	//cout<<i<<'\n';
	for(int j=i+1;j<=n;j++){
		dfs(j,sum&a[j],cnt+1);
	}
	return;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		}
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
	}
	else if(m==n-1){
		int ans1=a[1],ans2=a[2];
		for(int i=2;i<n;i++)ans1&=a[i];
		for(int i=3;i<=n;i++)ans2&=a[i];
		ans=max(ans1,ans2);
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=to_two(a[i]);
		if(cnt==n){
			sort(a+1,a+n+1,cmp);
			ans=a[m];
		}
		else for(int i=1;i<=n;i++){
			dfs(i,a[i],1);
		}
	}
	cout<<ans;
	return 0;
}

