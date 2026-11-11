#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int ans;
void dfs(int dep,int cnt,int now){
	if(cnt==m){
		ans=max(ans,now);
		return;
	}
	if(dep>n){
		return;
	}
	dfs(dep+1,cnt+1,(now&a[dep]));
	dfs(dep+1,cnt,now);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool f=0;
		for(int i=1;i<=31;i++){
			if(a[i]==((1<<i)-1)){
				f=1;
			}
		}
		if(!f){
			flag=0;
		}
	}
	if(n<=2000||m==n-1||m==1){
		dfs(1,0,(1<<21)-1);
		cout<<ans;
		return 0;
	}
	if(flag){
		sort(a+1,a+n+1);
		int cnt=a[n];
		for(int i=n-1;i>=n-m+1;i++){
			cnt&=a[i];
		}
		cout<<cnt;
		return 0;
	}
	bool fff=0;
	int x=0;
	for(int i=0;i<=20;i++){
		if(n==(1<<i)){
			fff=1;
			x=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			fff=0;
			break;
		}
	}
	if(fff){
		int y=0;
		for(int i=0;i<=30;i++){
			if(m<=(1<<i)){
				y=i;
				break;
			}
		}
		for(int i=x;i>=x-(x-y)+1;i--){
			ans+=(1<<(i-1));
		}
		cout<<ans;
		return 0;
	}
	cout<<511;
	return 0;
}