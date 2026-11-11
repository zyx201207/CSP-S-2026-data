#include<bits/stdc++.h>
#define maxn 500005
#define maxm 300005
using namespace std;
int n,m;
int a[maxn];
int ans[maxm];
int g[maxm];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]]=i;
		if(a[i]<a[i-1])flag=0;
	}
	if(flag){
		for(int i=1;i<=m;i++){
			cout<<g[i];
			if(i<m)cout<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int p=i;
		while(p<=n){
			ans[a[p]]++;
			p=g[a[p]];
			p++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]; 
		if(i<m)cout<<" ";
	}
	return 0;
}
