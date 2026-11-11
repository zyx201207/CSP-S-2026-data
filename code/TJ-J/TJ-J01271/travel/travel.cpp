#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int e,f;
bool g,h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	e=(int)b[2];
	f=(int)d[2];
	if(e<=67){
		g=0;
	}else{
		g=1;
	}
	if(f<=67){
		h=0;
	}else{
		h=1;
	}
	if(g!=h){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(e-f!=1&&e-f!=-1){
		cout<<"0";
		return 0;
		
	}
	cout<<"1";
	return 0;
}
