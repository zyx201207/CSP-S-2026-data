#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int n,m;
ll a[200010],maxn=0,num[200010],vis[200010],maxs=0,ti=0;
ll yu(ll a,ll b){
	ll x=0,i=0;
	if(a==b)return a;
	while(a!=0&&b!=0){
		int xw=a%2,y=b%2;
		x+=pow(2,i)*(xw&&y);
		a/=2,b/=2;
		i++;
	}
	return x;
}
void dfs(int i){
	if(ti>=1e7){
		cout<<maxn;
		exit(0);
	}
	if(i==m+1){
		ll s;
		for(int j=1;j<m;j++){
			if(j==1)s=yu(a[num[j]],a[num[j+1]]);
			else s=yu(s,a[num[j+1]]);
		}
		maxn=max(s,maxn);
		ti++;
	}
	for(int j=num[i-1]+1;j<=n;j++){
		if(vis[j])continue;
		num[i]=j;
		vis[i]=1;
		dfs(i+1);
		vis[i]=0;
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    IO;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	maxs=max(maxs,a[i]);
	}
	if(m==1){
		cout<<maxs;
	}
	else {
		dfs(1);
		cout<<maxn;
	}
    return 0;
}
