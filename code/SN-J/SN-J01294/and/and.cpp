//SN-J01294
#include<bits/stdc++.h>
using namespace std;
int n,m,ans[200005];
long long a[200005],maxn=0,f=0;
void dfs(int now,int d){
	if(now==n+1 && d==m+1){
		long long sum=ans[1];
		for(int i=2;i<=m;i++){
			sum&=ans[i];
		}
		maxn=max(maxn,sum);
		return;
	}else if(now==n+1){
		return;
	}
	dfs(now+1,d);
	if(d==m+1){
		return;
	}else{
		ans[d]=a[now];
//		for(int i=1;i<=d;i++){
//			cout<<ans[i]<<" ";
//		}
//		cout<<endl;
		dfs(now+1,d+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}else if(m==n){
		long long sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}else if(n>2000){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}else{
		dfs(0,1);
		cout<<maxn;
		return 0;
	}
	
}
