#include<bits/stdc++.h>
using namespace std;
struct node{
	int fnt,nxt;
};
node e[500005];
bool vis[500005];
int ans[500005];
int a[500005];
int n,m;
int main(){
	
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	//freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=1;
	while(cnt<=n){
		memset(vis,0,sizeof(vis)); 
		e[a[cnt]].fnt=500001;
		e[a[cnt]].nxt=500001;
		int start=a[cnt];
		vis[a[cnt]]=true;
		int last=a[cnt];
		for(int i=cnt+1;i<=n;i++){
			if(!vis[a[i]]){
				vis[a[i]]=true;
				e[last].nxt=a[i];
				e[a[i]].fnt=last;
				e[a[i]].nxt=500001;
				last=a[i];
			}
			else{
				for(int u=a[i];u!=500001;u=e[u].nxt){
					vis[u]=false;
				}
				vis[a[i]]=true;
				e[a[i]].nxt=500001;
				last=a[i];
				if(e[a[i]].fnt==500001) start=a[i];
			}
		}
		
		
			
		for(int u=start;u!=500001;u=e[u].nxt){
			ans[u]++;
		}
		cnt++;
		
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
