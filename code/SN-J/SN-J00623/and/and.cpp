#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
long long mx;
long long a[N];
void dfs(int pos,int sum,long long ans){
	if(pos==n+1){
		if(sum==m)
			mx=max(mx,ans);
		return;
	} 
	if(sum==0)
		dfs(pos+1,sum+1,a[pos]);
	else
		dfs(pos+1,sum+1,ans&a[pos]);
	dfs(pos+1,sum,ans);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20)
		dfs(1,0,1);
	else if(m==1)
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
	else if(m==n){
		mx=a[1];
		for(int i=2;i<=n;i++)
			mx&=a[i];
	}
	else if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					mx=max(mx,a[i]&a[j]);
	}
	else{
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		for(int i=1;i<=n;i++)
			mx=max(mx,ans&a[i]);
	}
	cout<<mx;
	return 0; 
} 
