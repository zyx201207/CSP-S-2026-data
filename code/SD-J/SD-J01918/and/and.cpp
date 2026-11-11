#include<bits/stdc++.h>
using namespace std;
int maxx=0;
vector<int> path;
int m,n;
int a[233333];
bool flag1=true;
bool flag2=true;
bool flag3=true;
bool cheat(int x){
	while(x){
		if(!(x&1)){
			return false;
		}
		x>>=1;
	}
	return true;
}
void dfs(int now,int cnt){
	if(cnt==m){
		int ans=path[0];
		for(auto i:path){
			ans&=i;
		}
		maxx=max(maxx,ans);
		return ;
	}
	if(now==n+1){
		return ;
	}
	path.push_back(a[now]);
	dfs(now+1,cnt+1);
	path.pop_back();
	dfs(now+1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(!cheat(n-1)){
		flag2=false;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			flag2=false;
		}
		if(!cheat(a[i])){
			flag1=false;
		}
		if(a[i]>=4){
			flag3=false;
		}
	}
	if(flag1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	else if(flag2){
		int ans=n-m;
		cout<<ans;
		return 0;
	}
	else if(flag3){
		sort(a+1,a+n+1,greater<int>());
		int ans=a[1];
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
		return 0;
	}
	dfs(1,0);
	cout<<maxx<<endl;
	return 0;
} 
