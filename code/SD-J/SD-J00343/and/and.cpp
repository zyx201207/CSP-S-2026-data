#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m,ans=0,a[MAXN],and01[MAXN];
bool b[MAXN];
void dfs(int cnt){
	if(cnt==m)ans=max(ans,and01[m]);
	for(int i=1;i<=n;i++){
		if(!b[i]){
			and01[cnt+1]=a[i]&and01[cnt];
			b[i]=1;
			dfs(cnt+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			int sumand=2147483647;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				sumand&=a[j];
			}
			ans=max(ans,sumand);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	and01[0]=2147483647;
	dfs(0);
	cout<<ans;
	return 0;
}
