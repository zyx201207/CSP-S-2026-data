#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[300005],vis[300005],b[500005];
vector<int>card;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)vis[j]=0;
		for(int j=n;j>=i;j--){
			if(vis[b[i]])continue;
			else a[b[i]]++,vis[b[i]]=1;
		}
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
