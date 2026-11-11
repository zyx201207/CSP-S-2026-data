#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+7;
int n,m;
int a[N];
int vis[N];
map<long long,int> mp;
map<long long,int> mp1;
map<long long,int> mp2; 
void dfs(int x,int dep){
	if (dep<mp1[x]) mp1[x]=dep,mp2[x]=1;
	else if (dep==mp1[x]) mp2[x]++;
	for (int i=a[x]-m;i<=a[x]+m;i++){
		if (mp.count(i)){
			if (vis[mp[i]])continue;
			vis[mp[i]]=1;
			dfs(mp[i],dep+1);
			vis[mp[i]]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			mp1[i]=1e9+7;
			mp2[i]=1;
			mp[a[i]]=i;
		}
		int cnt=0;
		for (int i=1;i<=n;i++){
			vis[i]=1;
			dfs(i,1);
			vis[i]=0;
			for (int j=1;j<=n;j++){
				if (mp2[j]==2){
					cnt++;
				}
			}
			mp2.clear();
		}
		cout<<cnt<<"\n";
	} 
}
