#include<bits/stdc++.h>
using namespace std;
int n,m,a[323232],as[323232]; 
bool flag[5200];
unordered_map<int,int> l,ans;
vector<int>pos[323232]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],l[a[i]]++,pos[a[i]].push_back(i);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(flag,0,sizeof flag);
			for(int j=i;j<=n;j++){
				if(flag[a[j]]==1){
					for(int k=j-1;k>=i;k--) flag[a[k]]=0;
				}
				flag[a[j]]=1;
//				cout<<"Number "<<a[j]<<" Status:"<<flag[a[j]]<<'\n';
			}
			for(int o=1;o<=m;o++){
				if(flag[o]) ans[o]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		exit(0);
	} 
	for(int i=1;i<=n;i++){
		as[a[i]]=max(as[a[i]],n-i+1);
		if(pos[a[i]].size()>1) as[a[i]]--;
	}
	for(int i=1;i<=m;i++) cout<<as[i]<<' ';
	return 0;
}
