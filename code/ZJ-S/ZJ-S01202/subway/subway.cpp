#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100010],k[100010],a[10010][10010]{},t[10010][10010]{},ans=1e9;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x;
			a[i][x]=x;
			cin>>t[i][x];
		}
	}
	for(int i=1;i<=m;i++){
		if(a[1][i]!=0&&a[2][i]!=0){
			ans=min(ans,t[1][i]+t[2][i]);
		}
	}
	while(q--){
		long long o,g;
		cin>>o>>g;
		long long sum=1e9;
		if(n==1){
			cout<<a[1][o]+a[1][g]+w[o]+w[g]<<"\n";
		}
		else if(n==2){
			if(a[1][o]!=0&&a[1][g]!=0)
			sum=t[1][o]+t[1][g]+w[o]+w[g];
			if(a[2][o]!=0&&a[2][g]!=0)
			sum=min(sum,t[2][o]+t[2][g]+w[o]+w[g]);
			if(a[1][o]!=0&&a[2][g]!=0)
			sum=min(sum,t[1][o]+t[2][g]+w[o]+w[g]+ans);
			if(a[2][o]!=0&&a[1][g]!=0)
			sum=min(sum,t[2][o]+t[2][g]+w[o]+w[g]+ans);
			cout<<sum<<"\n";
		}
	}
	return 0;
}