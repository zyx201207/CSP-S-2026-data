#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,ps,ta=1,tb=1;
ll a[200005],ans;
void dfs(int t,int s,int x){
	if(x==m){
		ans=max(ans,s*1ll);
		return ;
	}
	if(t>n){
		return ;
	}
	for(int i=t+1;i<=n;i++){
		if(t==0){
			dfs(i,a[i],x+1);
		}
		else{
			dfs(i,s&a[i],x+1);
		}
	}
	dfs(t+1,s,x);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			ps=a[1];
		}
		ps&=a[i];
		if(int(log(a[i]+1)/log(2))!=(log(a[i]+1)/log(2))){
			ta=0;
		}
		if(a[i]!=i-1||int(log(n)/log(2))!=(log(n)/log(2))){
			tb=0;
		}
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(0,0,0);
		cout<<ans;
	}
	else if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		cout<<ps;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(ta==1){
		for(int i=n,t=1;t<=m&&i>=1;i--){
			if(t==1){
				ans=a[i];
			}
			ans&=a[i];
			t++;
		}
		cout<<ans;
	}
	else{
		cout<<ps;
	}
	return 0;
}
/*
4 2 
3 12 12 15
*/

