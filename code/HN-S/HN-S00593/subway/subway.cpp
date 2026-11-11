#include<bits/stdc++.h>
using namespace std;
long long o,m,q,n,d,a[2000005],b[200005][10],sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>o>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		sum+=a[i];
	}
	cout<<sum;
	
	
	
	return 0;
} 
