#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[5005];
int ans[3005];
bool vis[3005];
bool ansvis[3005];
stack <int> z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=0;i<=n-1;i++){
		memset(vis,0,sizeof(vis));
		memset(ansvis,0,sizeof(ansvis));
		for(int j=i+1;j<=n;j++){
			if(vis[num[j]]){
				while(z.top()!=num[j]){
					vis[z.top()]=false;
					z.pop();
				}
				z.pop();
			}
			vis[num[j]]=true;
			z.push(num[j]);
		}
		while(!z.empty()){
			ansvis[z.top()]=true;
			z.pop();
		}
		for(int k=1;k<=m;k++){
			ans[k]+=int(ansvis[k]);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}

	return 0;
}
