#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(i==1&&a[n]==1) cout<<n<<" ";
		else if(i==1) cout<<n-1<<" ";
		else if(i==m&&a[n]==m) cout<<n<<" ";
		else if(i==n) cout<<n-1<<" ";
		else cout<<b[i]<<" ";
	}
	return 0;
}
