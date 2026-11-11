#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],mm[300005],idx;
int vis[500005]={},mp[500005]={};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		idx=0;
		memset(vis,-1,sizeof(vis));
		memset(mp,-1,sizeof(mp));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=-1){
				idx=vis[a[j]]-1;
			}
			mp[++idx]=a[j];
			vis[a[j]]=idx;
		}
		for(int j=1;j<=idx;j++){
			mm[mp[j]]++;
//			cout<<mp[j]<<" ";
		}
//		cout<<endl<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<" ";
	}
	
	return 0;
} 
