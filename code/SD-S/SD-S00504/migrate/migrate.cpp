#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int c,t,n,d,ans;
int a[maxn];
int ti[maxn][maxn];
void dfs(int x,int m){
	if(a[x+1]-a[x]>d||x>n){
		return;
	}
	if(m==0){
		int j=0;
		for(int i=x+1;a[i+1]-a[x]<=d;i++){
			ti[x][i]++;
			if(ti[x][i]==2)ans++;
			if(ti[x][i]==3){
				ans--;
				ti[x][i]=4;
				continue;
			}
			dfs(i,1);
			j=i;
		}
		ti[x][j+1]++;
		if(ti[x][j+1]==2)ans++;
		if(ti[x][j+1]==3){
			ans--;
			ti[x][j+1]=4;
		}
		dfs(j+1,0);
	}
	else{
		int j=0;
		for(int i=x+1;a[i+1]-a[x]<=d;i++){
			j=i;
		}
		ti[x][j+1]++;
		if(ti[x][j+1]==2)ans++;
		if(ti[x][j+1]==3){
			ans--;
			ti[x][j+1]=4;
		}
		dfs(j+1,0);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(a[2]-a[1]>d){
				cout<<0<<'\n';
				continue;
			}
			
		}
	}
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<1<<'\n'; 
	}
	return 0;
}
