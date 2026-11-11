#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005],vis[500005];
vector<int> v;
int find(int x){
	for(int i=0;i<int(v.size());i++){
		if(v[i]==x&&vis[i]==0){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		v={}; 
		for(int j=i;j<=n;j++){
			int  idx=find(a[j]);
			if(idx!=-1){
				for(int k=idx;k<int(v.size());k++){
					vis[k]=1;
				}
			}
			v.push_back(a[j]);
		}
		for(int j=0;j<int(v.size());j++){
			//cout<<vis[j]<<" ";
			if(vis[j]==0){
				cnt[v[j]]++;
			}
		}
		//cout<<endl;
	}
	for(int  i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}//fkw
	return 0;
} 
