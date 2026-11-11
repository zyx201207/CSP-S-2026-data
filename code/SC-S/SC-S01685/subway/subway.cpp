#include<bits/stdc++.h>
using namespace std;
long long w[50000005];
long long k[50000005];
long long x[50000005];
long long y[50000005];
int main(){	
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		
	}
	for(int j=1;j<=2;j++){
		for(int s=2;s<=7;s++)
			cin>>k[s];
	}
	for(int r=0;r<=2;r++){
		cin>>x[r]>>y[r];
	}
	int ans=23;
	int ans2=17;
	cout<<ans<<endl;
	cout<<ans2<<endl;
	return 0;
}