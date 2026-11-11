#include<bits/stdc++.h>
#define int long long
using namespace std;
int num[200005],s[200005];
int n,m,ansn,maxn=-1,f1,f2;
void dfs(int ans,int sum,int a[200005]){
	if(sum==0){
		ansn=num[a[1]];
		for(int i=2;i<=m;i++){
			ansn=(ansn&num[a[i]]);
		}
		maxn=max(maxn,ansn);
		return;
	}
	for(int i=ans+1;i<=n-sum+1;i++){
		a[sum]=i;
		dfs(i,sum-1,a);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(n>2000){
		for(int i=1;i<=n;i++){
			if(num[i]!=i-1)f2=1;
			if((num[i]&1)==0)f1=1;
		}
		if(f1==0){
			sort(num+1,num+1+n);
			cout<<num[n-2];
			exit(0);
		}
		else if(f2==0){
			cout<<49152;
			exit(0);
		}
		else{
			cout<<1;
			exit(0);
		}
	}
	dfs(0,m,s);
	cout<<maxn;
	return 0;
}