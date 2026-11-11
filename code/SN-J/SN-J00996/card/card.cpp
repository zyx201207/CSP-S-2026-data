#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],tj[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int b[500005]={0};
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			if(b[i]==a[j]) b[i]=0;
			if(b[j]==i) tj[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tj[i]<<" ";
	}
	return 0;
} 
