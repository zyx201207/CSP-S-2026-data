#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N],t[M],ans[M],sum[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		sum[i]=sum[i-1]+t[i];
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}

