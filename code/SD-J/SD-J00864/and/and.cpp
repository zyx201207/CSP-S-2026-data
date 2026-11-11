#include<bits/stdc++.h>
using namespace std;
int v[200005];
int q[200005],h[200005];
int k[9];
int dmaxx=0;
int n,m;
void dfs(int dep,int cnt,int ans){
	if(dep==n+1){
		if(cnt==m) dmaxx=max(dmaxx,ans);
		return ;
	}
	if(cnt>m) return ;
	if(ans==0) dfs(dep+1,cnt+1,v[dep]);
	else dfs(dep+1,cnt+1,ans&v[dep]);
	dfs(dep+1,cnt,ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=-1;
	int al;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		maxx=max(maxx,v[i]);
		if(v[i]<=4) k[v[i]] ++;
		if(i==1) al=v[i];
		al&=v[i];
	}
	q[1]=v[1];
	h[n]=v[n];
	for(int i=2;i<=n;i++){
		q[i]=q[i-1]&v[i];
		h[n-i+1]=h[n-i+2]&v[n-i+1];
	}
	if(m==n-1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,q[i-1]&h[i+1]);
		}
		cout<<maxx;
		return 0;
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<dmaxx;
		return 0;
	}
	if(maxx<=4){
		int ans=0;
		if(k[2]+k[3]>=m) ans=2;
		else if(k[1]+k[3]>=m) ans=1;
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	maxx=-1;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxx=max(maxx,v[i]&v[j]);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<al;
		return 0;
	}
	sort(v+1,v+1+n);
	int ans=v[n];
	for(int i=1;i<=m;i++){
		ans&=v[n-i+1];
	}
	cout<<ans;
	return 0;
}
