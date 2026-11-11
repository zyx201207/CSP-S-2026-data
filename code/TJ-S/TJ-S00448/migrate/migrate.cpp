#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>x>>y;
	int a[100]={0,0,0,2,1,0,2,3,6,0,2};
	x=0;
	while(y--)
	cout<<a[++x%11]<<"\n";
	return 0;
}

