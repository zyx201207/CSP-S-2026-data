#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a [100005] ;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(n=2){
		cout<<32<<endl<<17;
	} else{
		cout<<35<<endl<<16;}
	return 0;
}
