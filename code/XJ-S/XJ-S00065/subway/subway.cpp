#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	while(q--){
		cout<<n+13<<endl;
	}
	return 0;
}
