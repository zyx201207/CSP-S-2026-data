#include<bits/stdc++.h>
using namespace std;
int ans[300010];
int card[500010];
int now[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		memset(now,0,sizeof now);
		for(int j=i;j<=n;j++){
			int f=0;
			for(int u=1;u<=cnt;u++){
				if(now[u]==card[j]){
					f=u;
					break;
				}
			}
			if(f==0){
				cnt++;
				now[cnt]=card[j];
			}
			else{
				for(int u=f+1;u<=cnt;u++){
					now[u]=0;
				}
				cnt=f;
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[now[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
