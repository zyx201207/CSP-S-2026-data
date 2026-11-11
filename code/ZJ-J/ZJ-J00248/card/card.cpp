#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],last[M],p[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			p[a[j]]++;
			j=last[a[j]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	return 0;
}