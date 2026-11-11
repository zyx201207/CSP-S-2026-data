#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("add.in","t",stdin);
	freopen("add.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx=0;
 for(int i=1;i<=n;i++){
 	int x;
 	cin>>x;
 	maxx=max(maxx,x);
}	
 	cout<<maxx;
	return 0;
}
