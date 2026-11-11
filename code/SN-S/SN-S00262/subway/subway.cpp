#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int c,n,m,d,q,w[50050],k[550],a[50050],t[50050],x[100050],y[100050];
int main(int argc, char** argv) {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	
	return 0;
}
