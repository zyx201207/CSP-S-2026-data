#include<bits/stdc++.h>
using namespace std;
int a,b;
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a!=b) cout<<"0000";
	else if(x[0]!=y[0]||x[1]!=y[1]) cout<<"1000";
	else if(!(x[2]<='C'&&y[2]<='C')&&!(x[2]>='D'&&y[2]>='D')) cout<<"1100";
	else if(min(x[2],y[2])+1!=max(x[2],y[2])) cout<<"1110";
	else cout<<"1111";
	return 0;
}
