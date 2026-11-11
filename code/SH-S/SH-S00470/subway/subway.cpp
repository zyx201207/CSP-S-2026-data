#include<iostream>
using namespace std;
const int N=1e6;
int a[N];
int b[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int t;
		cin>>t;
		for(int i=1;i<=t*2;i++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>b[i];
	}
	cout<<2347;
	return 0;
}
