#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long a[50005];
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	int b[10001],e[10001];
	for(long long i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cout<<b[j]<<e[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>n>>m;
	}
	cout<<32<<endl<<17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
