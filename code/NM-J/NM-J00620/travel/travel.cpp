#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string ans;
	if(a[0]!=c[0]||a[1]!=c[1]){
		ans="0000";
	}
	else if(b[0]!=d[0]||b[1]!=d[1]){
		ans="1000";
	}
	else if((b[2]<68&&d[2]>67)||(b[2]>67&&d[2]<68)){
		ans="1100";
	}
	else if((b[2]-d[2]>1)||(b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')){
		ans="1110";
	}
	else {
		ans="1111";
	}
	cout<<ans;
	//'a'=97,'A'=65;
	return 0;
} 
