#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
int n,m,p[30];
int maxn=-1e18;
void dfs(int pos,int x){
	if(pos>n&&x!=0){
		return; 
	}
	if(pos>n){
		int ans=-1;
		for(int i=1;i<=n;i++){
			if(p[i]==1&&ans==-1)ans=a[i];
			else if(p[i]==1)ans&=a[i];
		}
		maxn=max(maxn,ans);
		return;
	}
	if(x>0){
		p[pos]=1;
		dfs(pos+1,x-1);
		p[pos]=0;
		dfs(pos+1,x);
	}else{
		dfs(pos+1,x);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n<=20){
		dfs(1,m);
		cout<<maxn;
		return 0;
	}
	
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	
	if(m==2&&n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) {
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	
	int cnt=0;
	for(int i=1;i<=n-1;i++){
		if(a[i]+1!=a[i+1]&&a[i]%2==1&&a[i+1]%2==1){
			cnt++;
			break;
		}
	}
	if(cnt==1){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(cnt==0){
		sort(a+1,a+n+1);
		if(m<=n/2){
			cout<<n/2;
		}else{
			cout<<0;
		}
		return 0;
	}
	return 0;
} 
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
