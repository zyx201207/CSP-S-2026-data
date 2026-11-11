#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	char t;
	int r=1,u=0;
	do{
		t=getchar();
		if(t=='-')r=-r;
	}while(t<'0'||t>'9');
	while(t>='0'&&t<='9'){
		u=u*10+t-'0';
		t=getchar();
	}return u*r;
}string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}else if(!(b[0]==d[0]&&b[1]==d[1])){
		cout<<"1000";
	}else if(!((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))){
		cout<<"1100";
	}else if(abs(b[2]-d[2])>1){
		cout<<"1110";
	}else cout<<"1111";
	return 0;
}
