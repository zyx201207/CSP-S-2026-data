#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[5005],cnt[5005];
long long ans[300005];
bool f1=true,f2=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f1=false;
		if(a[i]!=a[i-1]) f2+=1;
	} 
	if(n<=5000){
		stack<int> sta;
		bool vis[3005];
		for(int j=1;j<=n;j++){
			for(int i=1;i<=m;i++) vis[i]=0;
			for(int i=j;i<=n;i++){
				if(vis[a[i]]){
					while(sta.top()!=a[i]) {
						if(sta.top()!=a[i]){
							vis[sta.top()]=0;
							sta.pop();
						} 
					}
				}else{
					sta.push(a[i]);
					vis[a[i]]=1;
				}
			}
			for(int i=1;i<=m;i++) ans[i]+=vis[i];
		}
	}else if(f1){
		int x=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]!=x) {
				ans[x]=i-1;
				x=a[i];
			}
		}
	}else if(f2<5000){
		int tot=1;
		for(int i=2;i<=n;i++){
			if(a[i-1]==a[i]) cnt[tot]++;
			else{
				b[tot]=a[i-1];
				tot+=1;
			}
		}
		stack<int> sta;
		bool vis[3005];
		for(int j=1;j<=tot;j++){
			for(int i=1;i<=m;i++) vis[i]=0;
			for(int i=j;i<=tot;i++){
				if(vis[b[i]]){
					while(!sta.empty() && sta.top()!=b[i]) {
						if(!sta.empty() && sta.top()!=b[i]){
							vis[sta.top()]=0;
							sta.pop();
						} 
					}
				}
				else{
					sta.push(b[i]);
					vis[b[i]]=1;
				}
			}
			for(int i=1;i<=m;i++) ans[i]+=vis[i]*cnt[i];
		}
	}
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<" "; 

	return 0;
}
