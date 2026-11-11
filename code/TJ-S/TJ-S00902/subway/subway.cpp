#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<q;i++){
		if(i%2==1)	cout<<(n+m+d+q)<<endl;
		else cout<<(c+d-n-m-q)<<endl;
	}
	return 0;
}
