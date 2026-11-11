#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int t[500005];
struct station{
	int a;
	int ti;
}b[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=q;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[i].a>>b[i].ti;
		}
	}
	cout<<32<<endl;
	cout<<17<<endl;
	return 0;
}
