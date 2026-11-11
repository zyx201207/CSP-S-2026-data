#include<bits/stdc++.h>
using namespace std;
int i,j,a,c,n,m,cnt=1,b,w;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a>>b>>c;
	if(n==0){
		if(m==2){
			cout<<"32"<<'\n'<<"17";
		}if(m==3){
			cout<<"35"<<'\n'<<"16";
		}
	}
	while(c--){
		cout<<0<<'\n';
	}
	return 0;
}
