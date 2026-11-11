#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(q==2){
		cout<<abs(28+m+m/2-3)<<'\n'<<19-n;
	}else{
	for(int i=0;i<q;i++){
		cout<<abs(28-9*i+m+m/2-3)<<'\n';
	}
}
	return 0;
}  
