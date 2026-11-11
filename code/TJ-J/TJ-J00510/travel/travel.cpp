#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&b[1]==d[1]) cout<<1;
	else cout<<0;
	if(a==c&&b[1]==d[1]){
		if((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')) cout<<1;
		else cout<<0;
	}else cout<<0;
	if(a==c&&b[1]==d[1]){
		if((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')){
			if(d[2]==char(int(b[2])+1)||d[2]==char(int(b[2])-1)) cout<<1;
	        else cout<<0;
		}else cout<<0;
	}else cout<<0;
	return 0;
}
