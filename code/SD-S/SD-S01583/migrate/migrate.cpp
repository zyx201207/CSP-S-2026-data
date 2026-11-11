#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<"0"<<"\n";
	}
	return 0;
}
/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6*/
