#include<bits/stdc++.h> 
//#define int long long
using namespace std;
int dp[100010],n,m,a[100010],maxa,anda,ans,now,vis[100010];
void dfs(int x,int m,int now){
	if(m==0){
		ans=max(now,ans);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,m-1,now&a[i]);
			vis[i]=0;
		}
	}
}
int cnt0(int n){
	int ret;
	while(n){
		if(n%2==1)ret++;
		n/=2;
	}
	return ret;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)anda=a[i];
		maxa=max(a[i],maxa);
		anda&=a[i];
	}
	if(m==1){
		cout<<maxa;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n-1==m&&n>2000){
		int ve[500010],ans;
		memset(ve,-1,sizeof ve);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			ve[cnt0(a[i])]=a[i];
		}
		for(int i=1;i<=n;i++){
			if(ve[i]!=-1){
				bool f=1,ansis=1;
				for(int j=1;j<=n;j++){
					if(ansis&&!a[j]==ve[i]){
						ansis=0;
						ans=a[i];
					}
					if(a[j]==ve[i]&&f){
						f=0;
					}else{
						ans&=a[i];
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		cout<<anda;
		return 0;
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(i,m-1,a[i]);
			vis[i]=0;
 	   }	
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}
