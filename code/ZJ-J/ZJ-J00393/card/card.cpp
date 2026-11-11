#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000001];
int ans[1000001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int pos=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i+1]>a[pos])ans[a[i]]=i-pos+1;pos=i+1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
//Trick||Treat!