#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=3e5+10;
int n,m,arr[N],ans[M],a[M],b[M],l[M];
int vis[M],f[M];
vector<int> g[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<arr[i-1]){
			f=1;
		}
		a[arr[i]]++;
		b[arr[i]]++;
	}
	if(f==0){
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
		return 0;
	}
	//int y=0;
	for(int i=1;i<=n;i++){
		b[arr[i]]--;
		for(int k=1;k<=m;k++){
			a[k]=b[k];
		}
		memset(vis,0,sizeof(vis));
		int y=0;
		for(int j=i;j<=n;j++){
			//if(j==i) ans[arr[j]]++;
			if(a[arr[j]]>=2 && vis[arr[j]]==0){
				y++;
				vis[arr[j]]=1;
			}	
			else if(a[arr[j]]==1 && vis[arr[j]]==1){
				y--;
				vis[arr[j]]=0;
			}
			if(!y) ans[arr[j]]+=1;	
			a[arr[j]]--;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
