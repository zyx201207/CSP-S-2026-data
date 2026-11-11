#include<bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q,w[500005],l[505];
string qwe[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long int ki;
		cin>>ki;
		getline(cin,qwe[i]);
	}
	for(int i=1;i<=q;i++){
		long long int a,b;
		cin>>a>>b;
		cout<<(w[a]+w[b])<<endl;
	}
	return 0;
}
/*
*/