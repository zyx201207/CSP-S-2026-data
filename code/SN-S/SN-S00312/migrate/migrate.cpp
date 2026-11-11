#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005],mb,minn=1e9,dit,n,d;
void dfs(int x,int cnt){
	if(x>mb){
		if(cnt<minn){
			minn=cnt;
			dit=0;
		}
		else if(cnt==minn){
			dit++;
		}
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d)dfs(i,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=1e9;
				dit=0;
				mb=j;
				dfs(i,0);
				if(dit==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/










