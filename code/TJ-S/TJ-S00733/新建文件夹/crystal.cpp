#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1 i<=n i++){
		cin>>i;
	}
	k[1]=l[i];
} 
	for(int i=2 i<=n;i++){
		k[1]=l[i]-l[i-1];
		p[i]=k[i]*(i-1);
	}
	u[l]=p[l];
	for(int i=3 i<=n;i++){
		u[l]=p[l]+l[i-2];
		if(p[i]>m){
			cout<<i-1;
			return 0;
		}
	}
	
	cost<<i-1;
	return 0;
}
