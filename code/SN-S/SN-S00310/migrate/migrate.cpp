#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010];
struct node{
	int id,k;//岛屿编号,行走步数 
};
queue<node> q;
int c[2000010];
int p[2000010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int e,t;cin>>e>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int j=1;j<n-1;j++){
			for(int i=1;i<=n;i++){
				c[i]=0,p[i]=0;
			}
			q.push({j,1});
			while(!q.empty()){
				int x=q.front().id;
				int y=q.front().k;
				q.pop();
				if(p[x]==0||p[x]==y){
					p[x]=y;c[x]++;
				}else continue;
				for(int i=x+1;i<=n;i++){
					if(a[i]-a[x]<=d){
						q.push({i,y+1});
					}else{
						break;
					}
				}
			} 
			for(int i=1;i<=n;i++){
				if(c[i]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
