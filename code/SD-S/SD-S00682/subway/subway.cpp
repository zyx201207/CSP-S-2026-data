#include<bits/stdc++.h>
using namespace std;
int c,n,m,d;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>m>>c>>n>>d>>q;
	while(q--){
		cin>>m>>c>>n>>d;
		cout<<n*n/m+d*c+d%abs(m-n);
	}return 0;
}
