#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],ans=0;
bool v[N];
void dfs(int x,int cnt,int sum){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=x;i<=n;++i){
		if(cnt==0) dfs(i+1,cnt+1,a[i]);
		else dfs(i+1,cnt+1,sum&a[i]);
		dfs(i+1,cnt,sum);
	}
	return ;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=20) dfs(1,0,0);
	else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;++i){
				ans=max(ans,a[i]);
			}
		}
		if(m==2){
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		if(m==n){
			for(int i=1;i<=n;++i){
				ans&=a[i];
			}
		}
	}else{
		sort(a+1,a+n+1);
		ans=a[n-m+1];
	}
	cout<<ans;
	return 0;
} 
