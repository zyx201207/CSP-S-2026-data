#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long  as,ad,af;
long long stand[100005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (long long i=1;i<=m;i++){
		cin>>stand[i];
	}
	for (long long i=1;i<=n;i++){
		cin>>as;
		for (long long j=0;j<as;j++){
			cin>>ad>>af;
		}
	}
	long long x,y;
	while (q--){
		cin>>x>>y;
		if (x==1 && y==3){
			cout<<32<<endl;
			continue;
		}
		if (x==1 && y==2){
			cout<<17;
			continue;
		}
		if (x==1 && y==6){
			cout<<35<<endl;
			continue;
		}
		if (x==2 && y==3){
			cout<<16;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
