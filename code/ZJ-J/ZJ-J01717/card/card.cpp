#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,s[300005];map<int,int>vis;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=vis[a[j]];k<j;k++)vis[a[k]]=0;
			}
			vis[a[j]]=j;
		}
		for(int j=1;j<=m;j++)if(vis[j])s[j]++;
		vis.clear();
	}
	for(int j=1;j<=m;j++)cout<<s[j]<<' ';
}