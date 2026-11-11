#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char n,m,p,a;
	cin>>n>>m>>p;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=m;i++){
		int l,r; 
		cin>>l>>r;
		int f = 1;
		for(int j = l;j<=r;j++){
			f*=a[j];
		}
		if(f<p){
			cout<<f<<endl;
		}
		if(f>=p){
			cout<<f%p<<endl;
		}
	}
	return 0;
}

 
