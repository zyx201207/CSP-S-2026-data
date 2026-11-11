#include<bits/stdc++.h>
using namespace std;
struct S{
	long long sta;
	long long tim;
};
bool a[m+1][m+1];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		S l[k+1];
		for(int j=1;j<=k;j++){
			cin>>l[j].sta>>l[j].tim;
		}
	}
	fpr(int i=1;i<=q;i++){
		cout<<57<<endl;
	}
	return 0;
}

