#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[200005],n,m,ans=-1;
void dfs(int x,int now,int gs){
	if(gs==m+1){
		ans=max(ans,now);
		return;
	}
	if(x==n+1)return;
	if(now<ans)return;
	dfs(x+1,now&a[x],gs+1);
	dfs(x+1,now,gs);
}
int maxa=-1;
bool flag=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(log2(a[i]+1)!=int(log2(a[i]+1)))flag=1;
		maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout<<maxa;
		return 0;
	}
	if(m==2){
		int ans2=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)ans2=max(ans,a[i]&a[j]);
		}
		cout<<ans2;
		return 0;
	}
	if(maxa<4||!flag){
		int ans1=pow(2,30)-1;
		sort(a+1,a+1+n);
		for(int i=n;i>=n-m+1;i--){
			ans1&=a[i];
		}
		cout<<ans1;
		return 0;
	}
	int t=pow(2,30)-1;
	dfs(1,t,0);
	cout<<ans;
	return 0;
}
