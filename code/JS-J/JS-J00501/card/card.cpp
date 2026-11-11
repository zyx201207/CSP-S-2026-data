#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N],tot,vis[N],mp[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		tot=0;
		for(int j=i;j<=n;j++){
			bool flag=true;
			for(int k=1;k<=tot;k++){
				if(ans[k]==a[j]){
					tot=k;
					flag=false;
					break;
				}
			}
			if(flag==true)ans[++tot]=a[j];
		}

		for(int j=1;j<=tot;j++){
			if(vis[ans[j]]==0){
				mp[ans[j]]++;
				vis[ans[j]]=1;
			}
			// cout<<ans[j]<<" ";
		}
		// cout<<'\n';
		for(int j=1;j<=m;j++)vis[j]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}