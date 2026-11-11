#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,ans;
int a[N],ts[N];
bool vis[N];
void dfs(int x,int s,int t,int sum){
	if(s==x){
		ans=max(ans,sum);
		return ;
	}
	for(int i=t;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int o=(sum&a[i]);
			if(s==0) o=a[i];
			dfs(x,s+1,i,o);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f=1,fl=1,fl1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]&(a[i]+1))!=0) f=0;
		if(a[i]!=i-1) fl=0;
		if(a[i]>=4) fl1=0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
	}else if(n<=20){
		dfs(m,0,0,a[1]);
		cout<<ans;
	}else if(f){
		cout<<0;
	}else if(fl){
		int cnt=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			cnt=(cnt&a[i]);
		}
		cout<<cnt;
	}else{
		sort(a+1,a+n+1);
		int cnt=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			cnt=(cnt&a[i]);
		}
		cout<<cnt;
	}
	return 0;
}
