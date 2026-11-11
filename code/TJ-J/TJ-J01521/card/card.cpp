#include<bits/stdc++.h>
using namespace std;
int a[500005],f[500005];
vector<int> vis[500005];
int t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	long long n,m;
	cin>>n>>m; 
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		long long len=vis[a[i]].size();
		for(long long j=0;j<len;j++){
			long long it=vis[a[i]][j];
			if(f[it]==0){
				f[it]=i;
			}
		}
		vis[a[i]].push_back(i);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			while(f[j]!=0){
				j=f[j];
			}
			t[a[j]]++;
		}
	} 
	for(long long i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	/*
	如果第i张牌会被第j张牌抽走，那么中级j-i-1张牌只会在第i+1轮出现 
	外层循环遍历每一局游戏
	*/
	return 0;
}
