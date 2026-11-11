#include <bits/stdc++.h>
using namespace std;
int c,t,n,d; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int x[200010],ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		} 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bool vis[200010]={};
				queue<pair<int,int> > q;
				q.push({i,0});
				int fast=0,cnt=0;
				while(!q.empty()){
					int r=q.front().first,st=q.front().second;
					q.pop();
					int f=0;
					if(r==j){
						if(fast==st){
							cnt++;
						}
						if(fast==0){
							cnt++;
							fast=st;
						}
						f=1; 
					}
					if(f){
						continue;
					}
					for(int k=1;k<=d;k++){
						if(vis[k+r]) continue;
						vis[k+r]=1;
						q.push({k+r,st+1});
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
