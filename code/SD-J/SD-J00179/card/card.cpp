#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+300;
int a[N],n,m,endd[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		endd[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			j=endd[a[j]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
