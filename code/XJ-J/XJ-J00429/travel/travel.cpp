#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>c>>e>>b>>d>>f;
	if(a!=b)cout<<"0000";
	else if(c!=d)cout<<"1000";
	else if((e>='D'&&f>='D')||(f<='C'&&e<='C'))
	{
		if(e==f+1||e==f-1)cout<<"1111";
	    else cout<<"1110";
	}
	else cout<<"1100";
	return 0;
}