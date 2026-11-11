#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	if(a1!=a3){
		cout<<"0000";
	}
	else if(a2[0]!=a4[0]||a2[1]!=a4[1]){
		cout<<"1000";
	}
	else if(!(((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(a4[2]=='A'||a4[2]=='B'||a4[2]=='C'))||((a2[2]=='D'||a2[2]=='E')&&(a4[2]=='D'||a4[2]=='E'))))
cout<<"1100";
	else if(max(a2[2],a4[2])-min(a2[2],a4[2])>1)
	cout<<"1110";
	else 
	cout<<"1111";
	return 0;
}
