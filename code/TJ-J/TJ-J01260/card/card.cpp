#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],pm[M],p[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=pm[a[i]],pm[a[i]]=i;
	}
	for(int i=1;i<=m;i++) pm[i]=0;
	
	for(int k=1;k<=n;k++){
		vis[k-1]=1;
		for(int i=k;i<=n;i++)
			vis[i]=0;
		for(int i=k;i<=n;i++){
			if(!vis[p[i]])
				for(int j=p[i];j<i;j++)
					vis[j]=1;
		}
		for(int i=k;i<=n;i++)
			pm[a[i]]+=!vis[i];
	}
	for(int i=1;i<=m;i++){
		cout<<pm[i];
		if(i<m) cout<<' ';
	}
	cout<<endl;
	return 0;
}

