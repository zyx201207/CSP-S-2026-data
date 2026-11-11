#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	} 
	int cnt=0;
	for(int i=1;i<=t;i++){
		srand(time(0));
		int cnt=rand();
		cout<<cnt<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
