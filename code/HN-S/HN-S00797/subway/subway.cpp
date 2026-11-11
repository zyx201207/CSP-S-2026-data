#include<bits/stdc++.h>
using namespace std;
int C;
int n,m,d,q;
int w[500050];
int k[550];
int a[500050];
int t[500050];
int T[100010];
int x[1000010],y[1000010];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++)cout<<w[x[i]]+w[y[i]]+t[x[i]]+t[y[i]]<<endl;
	return 0;
}

