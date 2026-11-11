#include<bits/stdc++.h>
using namespace std;
int n,m,d[300005],a[500005],vis[500005];
stack<int>s;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(vis[k]==0&&a[j]==a[k]){
					for(int p=1;p<=j-k;p++){
						if(vis[k+p-1]==0){
							vis[k+p-1]=1;
							s.pop();
						}
					}
					break;
				}
			}
			s.push(a[j]);
		}
		while(!s.empty()){
			d[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
