#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[m];
	int a[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
