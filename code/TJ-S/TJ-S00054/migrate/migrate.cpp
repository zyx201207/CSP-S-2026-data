#include<bits/stdc++.h>
using namespace std;
const long long N=0;
int n,d,st;
int vis[2000005],a[2000005];
int dt;
map<int,int>mp;
void dfs(int s,int e,int xt){
	if(s==e){
		mp[xt]++;
	}
	for(int i=1+s;i<=s+d;i++){
		if(vis[i]||i>n||i<1)continue;
		vis[i]=1;
		dfs(i,e,xt+1);
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n>>d;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[i]<=d){
					continue;
				}
			    mp.clear();
				vis[i]=1;
				dfs(i,j,0);
				for(auto it:mp){
					if(it.second==2){
//						cout<<i<<j<<"\n"; 
						sum++;
						break;
					}
//			if(i==1&&j==4)cout<<it.first<<" "<<it.second<<"\n";
				}
				vis[i]=0;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
} 

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
