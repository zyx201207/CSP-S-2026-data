#include<bits/stdc++.h>
using namespace std;
//const int N=;
void maind(){
	string x,y,a,b;
	cin>>x>>a>>y>>b;
	if(x==y){
		cout<<1;
		if(a[0]+a[1]==b[0]+b[1]){
			cout<<1;
			if(!((a[2]>'C')^(b[2]>'C'))){
				cout<<1;
				if(a[2]+1==b[2]||b[2]+1==a[2]) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		maind();
	}
	return 0;
}

