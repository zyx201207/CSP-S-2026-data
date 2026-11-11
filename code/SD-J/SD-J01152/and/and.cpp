#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ans,a[2*100005],len,cnt=0,maxx=0;
char ch;
long long dp[2*100005];
string s;
bool cmp(long long s1,long long s2){
	return s1>s2;
}
int dfs(int st,int k){
	
	if(k==m){
		cnt=max(cnt,ans);
		if(cnt==maxx){
			cout<<cnt;
			exit(0);
		}
		return 0;
	}
	for(int i=st;i<=n;i++){
		
		if(k==0) ans=a[i];
		else ans=ans&a[i];
		
	
		dfs(i+1,k+1);
	}
}
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		
	}
	
	sort(a+1,a+n+1,cmp);
	dfs(1,0);
	cout<<cnt;
	return 0;
} 
