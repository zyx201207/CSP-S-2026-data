#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c; 
int t;
int n,d;
int a[N];
int maxx,maxi;
bool vis[N];
void dfs(int x,int fx,int bs){
	if(bs>maxx) return;
	if(x==fx){
		if(bs<maxx){
			maxi=1;
			maxx=bs;
		}
		else if(bs==maxx){
			maxi++;
		}
		return;
	}
	vis[x]=1;
	for(int i=x+1;i<=n;i++){
		if(abs(a[x]-a[i])<=d&&!vis[i]){
			dfs(i,fx,bs+1);
		}
		else break;
	}
	vis[x]=0;
}
void so(){
	int cnt=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			memset(vis,0,sizeof vis);
			maxx=1e9;
			maxi=0;
			dfs(i,j,0);
			if(maxi==2){
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		so();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
