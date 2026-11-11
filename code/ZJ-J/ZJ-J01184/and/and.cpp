#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
int ans;
void dfs(int sum,int pos,int tmp){
	if(sum==m){
		ans=max(ans,tmp);
		return;
	}
	for(int i=pos;i<=n-m+sum+1;i++){
		dfs(sum+1,i+1,tmp&a[i]);
	}
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=LLONG_MIN;
	cin>>a[1];
	int zong=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		zong=zong&a[i];
	}
	if(n<=20){
		for(int i=1;i<=n-m+1;i++){
			dfs(1,i+1,a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==1)cout<<mx;
	else if(m==n)cout<<zong;
	else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
}
/*
code by Ace
*/

