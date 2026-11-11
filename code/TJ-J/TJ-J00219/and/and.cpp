#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200009];
long long Ans=INT_MIN;
void dfs(long long ans,int pos,int got){
	if(got==m){
		Ans=max(Ans,ans);
		return;
	}
	if(pos>n)return;
	dfs((ans==-1?a[pos]:ans&a[pos]),pos+1,got+1);
	dfs(ans,pos+1,got);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int M=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		M=max(M,a[i]);
	}
	long long R=pow(2,floor(log2(M)));
	dfs(-1,1,0);
	cout<<Ans;
	return 0;
}
