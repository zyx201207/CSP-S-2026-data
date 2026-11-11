#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[2000003]={0,0,0,1};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int i=5,j=2;i<=2000003;i++){
		f[i]=f[i-1]+j;
		j++;
	}int n;
	cin>>n;
	while(n--){
		int m,d;
		cin>>m>>d;
		for(int i=0;i<m;i++){
			int a;
			cin>>a;
		}cout<<f[m];
	}
	return 0;
} 
