#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool b1,b2,b3,b4;
	b1=a==c;
	b2=b1&&b[0]==d[0]&&b[1]==d[1];
	b3=b2&&((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'));
	if(b3){
		if(b[2]<='C'&&d[2]<='C'){
			if(abs(b[2]-d[2])==1) b4=1;
		}
		if(b[2]>='D'&&d[2]>='D') b4=1;
	}
	cout<<b1<<b2<<b3<<b4;
	return 0;
}