#include<bits/stdc++.h>
using namespace std;
int n,m,x[500010],dp[500010],f,h[500010],q[500010],vis[500010],v[500010],fi[500010];
vector<int>ve[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]<x[i-1])
			f=1;
		int nn=ve[x[i]].size();
		ve[x[i]].push_back(i);
		if(nn==0)
			continue;
		h[ve[x[i]][nn-1]]=i,q[i]=ve[x[i]][nn-1];
	}
	if(f==0){
		for(int i=1;i<=m;i++){
			int nn=ve[i].size();
			cout<<ve[i][nn-1]<<" ";
			return 0;
		}
	}
	memset(fi,0x7f,sizeof(fi));
	for(int i=n;i>=1;i--){
		if(i>fi[x[i]])
			continue;
		int xx=0;
		for(int j=i-1;j>=1;j--){
			if(h[j]>i){
				xx=j;
				break;
			}
		}
		fi[x[i]]=xx,v[i]=xx,dp[x[i]]+=i-xx;
	}
	for(int i=1;i<=m;i++)
		cout<<dp[i]<<" ";
	return 0;
}