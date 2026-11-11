#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],ret[N];
long long n,m,mx;
void dfs(long long now,long long cnt){
	if(now>n){
		if(cnt==m){
			long long sum=ret[0];
			for(long long i=0;i<m;i++){
				sum&=ret[i];
			}
			mx=max(mx,sum);
		}
		return;
	}
	ret[cnt]=a[now];
	dfs(now+1,cnt+1);
	dfs(now+1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<mx;
	return 0;
}
