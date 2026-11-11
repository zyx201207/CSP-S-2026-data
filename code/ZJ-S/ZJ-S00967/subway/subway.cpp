#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
long long w[N];
long long t=1e10;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	//for(int i=1;i<=m;i++)cout<<w[i]<<endl;
	for(int i=1;i<=n;i++){
		int k;
		long long tt=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long x,y;
			cin>>x>>y;
			tt+=y;
		}
		t=min(t,tt);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<t+w[x]+w[y]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
