#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],anss;
int qz[200010],hz[200010];
void dfs(int x,int y,int sum){
	if(x>m){
		anss=max(anss,sum);
		return;
	}
	for(int i=y;i<=n-m+x;i++){
		if(sum&a[i]==0)continue;
		dfs(x+1,i+1,sum&a[i]);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,1,(1<<20)-1);
		cout<<anss; 
		return 0;
	}
	if(m==1){
		int ma=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma=max(ma,a[i]);
		}
		cout<<ma;
		return 0;
	}
	if(m==n){
		cin>>a[1];
		int ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
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
		int ans=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		qz[1]=a[1];
		hz[n]=a[n];
		for(int i=2;i<=n;i++){
			qz[i]=qz[i-1]&a[i];
		}
		for(int i=n-1;i>=1;i--){
			hz[i]=hz[i+1]&a[i];
		}
		ans=max(qz[n-1],hz[2]);
		for(int i=2;i<=n-1;i++){
			ans=max(ans,qz[i-1]&hz[i+1]);
		}
		cout<<ans;
		return 0;
	}
	int OK_B=1;
	int OK_4=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)OK_B=0;
		if(a[i]>=4)OK_4=0;
	}    
	if(OK_B){
		int ans=0;
		int mm=n-m;
		int k=n;
		int cnt=0;
		while((1<<cnt)<=n)cnt++;
		for(int i=cnt;i>=0;i--){
			if(mm>=(1<<i)){
				mm-=(1<<i);
				ans+=(1<<i);
			}
		}cout<<ans;
		return 0;
	}
	if(OK_4){
		int sum[4];
		for(int i=1;i<=n;i++){
			sum[a[i]]++;
		}
		if(m<=sum[3])cout<<3,exit(0);
		if(m<=sum[3]+sum[2])cout<<2,exit(0);
		if(m<=sum[3]+sum[1])cout<<1,exit(0);
		cout<<0,exit(0);
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}//-QwQ-
