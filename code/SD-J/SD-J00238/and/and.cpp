#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,mx,mn=1073741823;
void dfs(int p,long long ands,int num){
	
	if(num==m){
		ans=max(ans,ands);
		return;
	}
	if(p>n)return;
	if(n-p+num+1<m)return;
	dfs(p+1,ands&a[p],num+1);
	dfs(p+1,ands,num);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		mn&=a[i];
	}
	if(m==1)ans=mx;
	else if(m==n)ans=mn;
	else dfs(1,1073741823,0);
	cout<<ans;
	return 0;
}


