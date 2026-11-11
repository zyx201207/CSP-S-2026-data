#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	int x,y,z;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	x=rand();
	if (x>0) z=x;
	else if (x==0) z=321;
	else z=0-x;
	for (int i=0;i<z;i++){
		y=rand();
		if (y>0) cout<<y<<"\n";
		else if (y==0) cout<<321<<"\n";
		else cout<<0-y<<"\n";
	}
	return 0;
}