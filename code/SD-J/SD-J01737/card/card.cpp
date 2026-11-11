#include<bits/stdc++.h>
using namespace std;
int a[500005],t[500005],mp[500005],vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		memset(vis,0,sizeof vis);
		memset(t,0,sizeof t);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				cnt++;
				t[cnt]=a[j];
				vis[a[j]]=1;
			}
			else if(vis[a[j]]==1){
				cnt=0;
				memset(vis,0,sizeof vis);
				memset(t,0,sizeof t);
				cnt++;
				t[cnt]=a[j];
				vis[a[j]]=1;
				
			}
		}
		for(int k=1;k<=cnt;k++){
			mp[t[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}
