#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n,is[N],d,db;
void bfs(int st,int ed,int x){
	if(st==ed){
		if(x==2){
			db++;
		}
	}
	for(int i=ed;i>st;i--){
		if(is[i]<=is[st]+d){
			bfs(i,ed,x+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		memset(is,0,sizeof(is));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>is[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				db=0;
				if(is[j]-is[i]<=d){
					continue;
				}
				else if(is[j]-is[i]>2*d){
					break;
				}
				bfs(i,j,0);
				if(db==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}