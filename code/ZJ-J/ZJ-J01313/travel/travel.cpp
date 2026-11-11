#include<bits/stdc++.h>
using namespace std;
int a,b;
string stra,strb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>stra>>b>>strb;
	int c=(stra[0]-'0')*10+stra[1]-'0';
	int d=(strb[0]-'0')*10+strb[1]-'0';
	if(a!=b) cout<<"0000";
	else if(c!=d) cout<<"1000";
	else if((stra[2]<='C'&&strb[2]>'C')||(stra[2]>='D'&&strb[2]<'D')) cout<<"1100";
	else if(abs(int(stra[2]-strb[2]))!=1) cout<<"1110";
	else cout<<"1111";
	return 0;
}