#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]==70){
		b[2]--;
	}
	if(d[2]==70){
		d[2]--;
	}
	if(a[0]!=c[0]||a[1]!=c[1]){
		cout<<"0000";
	}else if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"1000";
	}else if(b[2]<=67&&d[2]>=68){
		cout<<"1100";
	}else if(abs(b[2]-d[2])>1){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
