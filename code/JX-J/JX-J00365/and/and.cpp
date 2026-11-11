#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],x,y,z;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);ey
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>x){
			x=a[i];
			y=i;
		}
	}
	a[y]=-1;
	m-=1;
	while(m--){
		for(int i=1;i<=n;i++){
			z=max(z,a[i]);
			if(z==a[i]) y=i;
		}
		a[y]=-1;
		x&=z;
		z=0;
	}
	cout<<x;
	return 0;
}
