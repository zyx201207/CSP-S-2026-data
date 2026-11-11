#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
int ans=-1,n,m;

void dfs(int u,int cnt,int sum){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}if(u==n+1) return;
	
	if(sum==-1){
		dfs(u+1,cnt+1,a[u]);
		dfs(u+1,cnt,-1);
	}else{
		dfs(u+1,cnt+1,sum&a[u]);
		dfs(u+1,cnt,sum);
	}
}

bool judge(int x){
	int u=x+1;
	while(u>1){
		if(u%2!=0) return 0;
		u/=2;
	}
	return 1;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>n>>m;
	bool flag=1;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!judge(a[i])) flag=0;
	}
	
	sort(a+1,a+1+n);
	
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++) sum=sum&a[i];
		cout<<sum<<endl;
		return 0;
	} 
	
	if(flag){
		//A
		cout<<a[n-m+1]<<"\n";
		return 0;
	}
	
	flag=1;
	int t=n;
	while(t>1){
		if(t%2!=0){
			flag=0;
			break;
		}
		t/=2;
	}
	if(flag){
		//B
		int sum=a[n];
		for(int i=n-1;i>=n-m+1;i--) sum=sum&a[i];
		cout<<sum<<"\n";
		return 0;
	}
	
	dfs(1,0,-1);
	
	cout<<ans<<"\n";
	
	return 0;
}
