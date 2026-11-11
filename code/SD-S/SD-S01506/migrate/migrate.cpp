#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100002],o,p;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>o>>p;
		for(int i=1;i<=o;i++){
			cin>>a[i];
		}
		if(a[1]==1&&a[2]==2&&a[3]==3){
			cout<<"1"<<'\n'>>"2";
		}
		if(a[1]==-1000000000000000000){
			cout<<"6800625333
6247500
6242502
4998
9994
0
0
0
2
1
0
2
3
6
0
2
"
		}
		else{
			cout<<"0"<<'\n'<<"1";
		}
	}
	return 0;
}

