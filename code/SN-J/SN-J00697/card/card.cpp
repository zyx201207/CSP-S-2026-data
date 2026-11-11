
//gaozixiu xianshidiliuzhongxue SN-J00697
#include<bits/stdc++.h>
using namespace std;
int a[50005];
int vis[500005];
int cha[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool ifA=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!(a[i-1]<=a[i]))ifA=0;
	}
	if(ifA){
		cout<<n-m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]])memset(vis,0,sizeof(vis));
			vis[a[j]]=1;
		}
		for(int i=1;i<=m;i++)ans[i]+=vis[i];
	}
			
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
