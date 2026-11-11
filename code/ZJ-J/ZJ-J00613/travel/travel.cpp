#include<bits/stdc++.h>
using namespace std;
int m;
string a,b,c,d;
bool x1,x2,x3,x4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		x1=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			x2=1;
			if(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C'){
				x3=1;
				m=b[2]-d[2];
				if(abs(m)==1)x4=1;
			}
		}
	}
	cout<<x1<<x2<<x3<<x4;
	
	return 0;
}
