#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
long long a[200010],x,ans;
void dfs(int pos,int num,long long sum){
	if(pos==n+1){
		if(num==m&&sum!=x) ans=max(sum,ans);
		return;
	}
	dfs(pos+1,num,sum);
	dfs(pos+1,num+1,sum&a[pos]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=((1<<31)-1);
	dfs(1,0,x);
	cout<<ans<<"\n";
	return 0;
}
