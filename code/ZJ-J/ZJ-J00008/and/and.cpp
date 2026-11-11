#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],l[200005],r[200005];
int ans;
void dfs(int i,int sum,int sum2){
	if(sum==m){
		ans=max(ans,sum2);
		return ;
	}
	if(i==n+1) return ;
	dfs(i+1,sum+1,sum2&a[i]);
	dfs(i+1,sum,sum2);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int sum=(1<<30)-1;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		sum&=a[i];
	}
	if(n<=20){
		dfs(1,0,(1<<30)-1);
		cout<<ans;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		int sum2=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j) continue ;
				sum2=max(sum2,a[i]&a[j]);
			}
		}
		cout<<sum2;
		return 0;
	}
	if(m==n-1){
		int sum1=(1<<30)-1;
		l[0]=sum1,r[n+1]=sum1;
		for(int i=1;i<=n;++i){
			sum1&=a[i];
			l[i]=sum1;
		}
		sum1=(1<<30)-1;
		for(int i=n;i>=1;--i){
			sum1&=a[i];
			r[i]=sum1;
		}
		int summ=0;
		for(int i=1;i<=n;++i){
			summ=max(l[i-1]&r[i+1],summ);
		}
		cout<<summ;
		return 0;
	}
	int summ=(1<<30)-1;
	for(int i=n;i>=n-m+1;++i){
		summ&=a[i];
	}
	cout<<summ;
	return 0;
}
