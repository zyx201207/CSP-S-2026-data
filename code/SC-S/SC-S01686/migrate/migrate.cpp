#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
const int N=2000010;
int a[N],de[N],cn[N],ans,vis[N];
vector<int>g[N];
void bfs(){
	queue<int>q;
	q.push(1);
	memset(de,0x3f,sizeof de);
	de[1]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		vis[t]=0;
		for(int i=0;i<g[t].size();i++){
			int j=g[t][i];
			if(de[j]>de[t]+1){
				de[j]=de[t]+1;
				cn[j]=1;
				
			}
			else if(de[j]==de[t]+1){
				cn[j]++;
				
			}
			if(!vis[j]){
				vis[j]=1;
				q.push(j);
			}
			
			
		}
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int v=1;
			if(i-v!=0){
				while(a[i]-a[i-v]<=d&&i-v!=0){
					g[i-v].push_back(i);
					v++;
				}
			}
			
		}
		bfs();
		for(int j=1;j<=n;j++){
			if(cn[j]==2)ans++;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}