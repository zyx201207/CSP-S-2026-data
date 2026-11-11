#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,m,a[500005],vis[300005],ans[300005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		//vector<int> v;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			v.push_back(a[j]);
			vis[a[j]]++;
			if(vis[a[j]]>1){
				int x=v.back();
				vis[x]--;
				v.pop_back();
				while(v.back()!=x){
					vis[v.back()]--;
					v.pop_back();
				}
				
			}
			
		}
		//for(int j=0;j<v.size();j++)cout<<v[j]<<' ';cout<<'\n';
		//while(!v.empty())ans[v.back()]++,v.pop_back();
		for(int j=0;j<v.size();j++)ans[v[j]]++;
		v.clear();
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

