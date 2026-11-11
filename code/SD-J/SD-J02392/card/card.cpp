#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
int n,m;
bool vis[N],flag[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		if(vis[a[i]]){
			for(int j=1;j<=i;j++){
				vis[a[j]]=0;
			}
		}
		vis[a[i]]=1;
		for(int j=1;j<=n;j++){
			if(vis[a[j]]==1&&!flag[a[j]]){
				sum[a[j]]++;
				flag[a[j]]=1;
			}else{
				continue;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
