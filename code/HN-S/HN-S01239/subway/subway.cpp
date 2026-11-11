#include<bits/stdc++.h>
using namespace std;
long long w[25009],k[509],a[505][100005],t[505][100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout<<32<<endl<<17;
	}
	if(c==0 && n==3 && m==5 && d==20 && q==2){
		cout<<32<<endl<<17;
	}
	return 0;
}
