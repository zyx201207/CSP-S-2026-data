#include<bits\stdc++.h>

using namespace std;
const int N=2e5+5;
int n,m,a[N],maxx=-1,vis[N];
void dfs(int k){
	if(k==n+1){
		int w=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				if(w==0)	w=a[i];
				else w&=a[i];
				++cnt;
			}
		}
		if(w>maxx&&cnt==m)	maxx=w;
		return ;
	}
	vis[k]=1;
	dfs(k+1);
	vis[k]=0;
	dfs(k+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);//zn cin cout
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(n<=20){
		maxx=-1;
		dfs(1);
		cout<<maxx;
		return 0;
	}
	else if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)	continue;
				int w=a[i]&a[j];
				if(w>maxx){
					maxx=max(maxx,w);
				}
			}
		}
		cout<<maxx;
	}
	else{
		sort(a+1,a+1+n);
		int s=a[n];
		for(int i=n-1,j=2;i>=1,j<=m;i--,j++){
			s&=a[i];
		}
		cout<<s;
	}
	return 0;
} 
