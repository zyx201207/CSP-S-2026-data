#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
struct node{
	int u,v,len;
};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,m,a[20001],xxx=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				queue<node> q;
//				cout<<v<<" "<<u<<":"<<endl;
				int maxn=INT_MAX,ans=0;
				q.push({u,1,0});
				while(!q.empty()){
					int x=q.front().u,y=q.front().v,len=q.front().len;
//					cout<<x<<" "<<y<<" "<<len<<endl;
					q.pop(); 
					if(x==v){
						if(len<maxn){
							maxn=len;
							ans=0;
						}
						if(len==maxn){
							ans++;
						} 
						continue;
					}
					for(int i=x+1;i<=v;i++){
						if(a[i]-a[x]<=m){
							q.push({i,y,len+1});
						}
					}
				}
//				cout<<"ans:"<<ans<<endl;
//				cout<<endl;
				if(ans==2){
					xxx+=1;
//					cout<<"xxx:"<<xxx<<endl;
				}
			}
		}
		cout<<xxx;
	}
	return 0;
}

