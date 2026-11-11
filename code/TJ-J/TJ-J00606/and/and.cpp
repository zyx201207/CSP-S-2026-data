#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1e4;
long long a[200005],t[200005];
void dfs(long long step,long long se){
	if(se>m){
		return;
	}
	if(step==n+1){
		if(se==m){
			long long sum=0;
			bool flag=0;
			for(int i=1;i<=step;++i){
				if(t[i]==1){
					if(flag==0){
						flag=1;
						sum=a[i];
					}
					else{
						sum&=a[i];
					}
				}
			}
			maxn=max(maxn,sum);
		} 
		return;
	}
	for(t[step]=0;t[step]<=1;++t[step]){
		if(t[step]==0){
			dfs(step+1,se);
		}
		else if(t[step]==1){
			if(step!=1){
				dfs(step+1,se+1);
			}
			else if(step==1){
				dfs(step+1,se+1);
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
}
