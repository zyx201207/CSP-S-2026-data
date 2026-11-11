#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int q[300001];
bool vis[300001];
vector<int>v[500001];
int d[300005];
int s[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n>=500){
		for(int i=n;i>=1;--i){
			d[a[i]]=max(d[a[i]],i);
		}
		for(int i=1;i<=m;++i){
			cout<<d[i]<<' ';
		}
		return 0;
	}
	for(int i=n;i>=1;--i){
		if(!vis[a[i]])d[a[i]]=i;
		vis[a[i]]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			vis[i]=0;
		}
		for(int j=i;j<=n;++j){
			vis[a[j]]=1;
			j=d[a[j]];
			s[a[j]]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<s[i]<<' ';
	}
}
