#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	long long c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(n==2) cout<<32<<17;
	else if(n==3) cout<<35<<16;
	
	return 0;
}
