#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int N=1e6+10;
int C,T,n,m,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		bool flag=1;
		L(i,1,n){
			cin>>a[i];
			if(i!=1 && a[i]-a[i-1]<=m) flag=0;
		}
		
		if(n<=3 || flag) cout<<"0\n";
		else if(n==4){
			if(a[3]-a[1]<=m && a[4]-a[2]<=m) cout<<"1\n";
			else cout<<"0\n";
		}else{
			cout<<"2\n";
		}
	}
	return 0;
}