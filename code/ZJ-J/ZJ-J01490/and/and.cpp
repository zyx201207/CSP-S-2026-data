#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200050];
bool count1(int x){
	long long y=a[x];
	while(y){
		if(y%2==0){
			return 0;
		}
		y>>=1;
	}
	return 1;
}
long long anss=0;
void dfs(int x,int cnt,long long sum){
	if(cnt==m){
		anss=max(anss,sum);
	}
	for(int i=x+1;i<=m-cnt+1;++i){
		dfs(i,cnt+1,sum&a[i]);
	}
}
long long ansss[200050];
long long dp1[200050];
long long dp2[200050];
void jisuan(){
	dp1[0]=68719476735;
	dp1[1]=a[1];
	for(int i=2;i<=n;++i){
		dp1[i]=dp1[i-1]&a[i];
	}
	dp2[n+1]=68719476735;
	dp2[n]=a[n];
	for(int i=n-1;i>=1;--i){
		dp2[i]=dp2[i+1]&a[i];
	}
	for(int i=1;i<=n;++i){
		ansss[i]=dp1[i-1]&dp2[i+1];
	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	long long ans=68719476735;
	sort(a+1,a+1+n);
	if(n==m){
		for(int i=1;i<=n;++i){
			ans&=a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==1){
		cout<<a[n]<<endl;
		return 0;
	}
	if(m==2){
		ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n-1){
		jisuan();
		long long sum=0;
		for(int i=1;i<=n;++i){
			sum=max(sum,ansss[i]);
		}
		cout<<sum<<endl;
		return 0;
	}
	bool xingzhiA=1;
	for(int i=1;i<=n;++i){
		if(!count1(i)){
			xingzhiA=0;
		}
	}
	if(xingzhiA){
		cout<<a[n-m+1]<<endl;
		return 0;
	}
	a[0]=68719476735;
	dfs(0,0,68719476735);
	cout<<anss<<endl;
	return 0;
} 

