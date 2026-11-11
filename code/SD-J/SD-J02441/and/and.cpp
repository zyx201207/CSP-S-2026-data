#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[200005];
int vis[20005];
struct stud{
	int x,y;
};
int maxx=-3e10;
void dfs(int sum,int s,int k){
	if(k==m){
		maxx=max(sum,maxx);
		return;
	}
	if(s+1>n){
		return;
	}
	for(int i=s+1;i<=n;i++){
		dfs((sum&a[i]),i,k+1);
	}
	return;
}
signed main(){
	//50 marks
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==n){
		int sum=2147483647;
		for(int i=1;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==1){
		int sum=-3e10;
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(n<=20){
		dfs(2147483647,0,0);
		cout<<maxx;
		return 0;
	}
	else if(n<=2005){
		if(m==n){
			int sum=2147483647;
			for(int i=1;i<=n;i++){
				sum=(sum&a[i]);
			}
			cout<<sum;
			return 0;
		}
		if(m==1){
			int sum=-3e10;
			for(int i=1;i<=n;i++){
				sum=max(sum,a[i]);
			}
			cout<<sum;
			return 0;
		}
		if(m==2){
			int sum=-3e10;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(a[i]!=a[j]){
						sum=max(sum,(a[i]&a[j]));
					}
				}
			}
			cout<<sum;
			return 0;
		}
	}
	else{
		sort(a+1,a+n+1);
		int sp=a[1]+1;
		int flag=1;
		for(int i=2;i<=min(n,(long long)15);i++){
			while(sp<=a[i]){
				sp*=2;
			}
			if(sp!=a[i]+1){
				flag=0;
				break;
			}
			sp=a[i]+1;
		}
		if(flag){
			int sum=2147483647;
			for(int i=n;i>=n-m+1;i--){
				sum=(sum&a[i]);
			} 
			cout<<sum;
			return 0;
		}
		else{
			int flga=1;
			for(int i=1;i<=n-1;i++){
				if(a[i]!=a[i+1]-1){
					flga=0;
					break;
				}
			}
			if(flga){
				int sum=2147483647;
				for(int i=n;i>=n-m+1;i--){
					sum=(sum&a[i]);
				}
				cout<<sum;
				return 0;
			}
			else{
				dfs(2147483647,0,0);
				cout<<maxx;
				return 0;
			}
		}
	}
	return 0;
} 






























