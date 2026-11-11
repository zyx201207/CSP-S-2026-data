#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000006];
int ne[1000006];
int la[1000006];
int ans[1000006];
int vis[1000006];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)ne[j]=0;
		for(int j=1;j<=m;j++){
			la[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(la[a[j]])ne[la[a[j]]]=j,la[a[j]]=j;
			else la[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0)ans[a[j]]++;
			vis[a[j]]=1;
			while(ne[j])j=ne[j];
		}
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
