#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=INT_MIN;
void dfs(int now,int x,int cnt){
	cout<<now<<" "<<x<<" "<<cnt<<"\n";
	if(cnt==m){
		ans=max(ans,now);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(i!=x)dfs(now&a[i],i,cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=1;i<=n;i++)dfs(a[i],i,1);
		cout<<ans;
	}
	else if(m==1){
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]%a[j]);
			}
		}
	}
	else{
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	return 0;
}
