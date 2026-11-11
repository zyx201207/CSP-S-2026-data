#include<bits/stdc++.h>
using namespace std;
int cas[500010];
int ans[300010];
int mo[500010];
bool vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cas[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,n,false);
		int len=0;
		for(int j=i;j<=n;j++){
			if(!vis[cas[j]]){
				vis[cas[j]]=true;
				len++;
				mo[len]=cas[j];
			}
			else{
				while(cas[j]!=mo[len]){
					vis[mo[len]]=false;
					len--;
				}
			}
		}
		cout<<i<<endl;
		for(int j=i;j<=n;j++){
			cout<<cas[j]<<' ';
			ans[cas[j]]+=vis[cas[j]];
			cout<<vis[cas[j]]<<endl;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
