#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,c;
	string b,d;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else if(b[1]!=d[1]||b[0]!=d[0])cout<<"1000";
	else if((b[2]<='C')!=(d[2]<='C'))cout<<"1100";
	else if(b[2]!=d[2]+1&&b[2]!=d[2]-1)cout<<"1110";
	else cout<<"1111";
	return 0;
}