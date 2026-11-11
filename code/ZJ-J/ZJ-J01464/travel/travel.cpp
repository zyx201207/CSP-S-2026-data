#include<bits/stdc++.h>
using namespace std;
long long g[7891];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	g['A']=g['B']=g['C']=1;
	g['D']=g['F']=2;
	long long a,b,c,d;
	char c2,c1;
	cin>>a>>b>>c1>>c>>d>>c2;
	if(a!=c){
		cout<<"0000";
	}else if(b!=d){
		cout<<"1000";
	}else if(g[c1]!=g[c2]){
		cout<<"1100";
	}else if(c1=='C'&&c2=='A'||c1=='A'&&c2=='C'){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
