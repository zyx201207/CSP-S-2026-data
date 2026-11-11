#include<bits/stdc++.h>
using namespace std;
const int M=5E5+5;
int a[M],b[M][2];
int main(){
	freopen("subway.in","r",stdin);	
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int j=1;j<=m;j++){
		cin>>a[j];
	}	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j][0]>>b[j][1];
		}
	}
	int l,r;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		cout<<a[l]+b[l][1]+b[r][1]+a[r]<<"\n";
	}
	return 0;
} 
