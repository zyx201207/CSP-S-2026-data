#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+9;
int n,m;
int a[N];
int ans[N];
bool vis[N];
int cnt[N];
int las[N],lass[N];
int tmp[N];
int lf[N];
bool A=1;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i-1]>a[i])A=0;
		cnt[a[i]]++;
		if(!lf[a[i]])lf[a[i]]=i;
	}
	if(A){
		for(int i=1;i<=m;i++)cout<<cnt[i]+lf[i]-1<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)las[j]=lass[j]=0;
		set<int>tmp;
		for(int j=i;j<=n;j++){
			if(las[a[j]])for(int k=las[a[j]];k<j;k++){
				las[a[k]]=lass[a[k]];
				tmp.erase(k);
			}
			tmp.insert(j);
			lass[a[j]]=las[a[j]];
			las[a[j]]=j;
		}
		for(auto v:tmp)ans[a[v]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
} 
