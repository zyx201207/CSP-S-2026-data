#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005];
vector<long long>a[502],t[502];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >>k;
		for(int j=1;j<=k;j++){
			int A,T;
			cin >>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<(y-x)*(y+x);
	}
	return 0;
}
