//zuoxianke 西安铁一中学 SN-J00679
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d;
char c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c1>>c>>d>>c2;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(b!=d){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(!((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C'))){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if((c1=='C'&&c2=='A')||(c1=='A'&&c2=='C'))cout<<0;
	else cout<<1;
}
