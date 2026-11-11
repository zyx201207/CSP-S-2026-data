#include <bits/stdc++.h>
using namespace std;
string s1,s2,x1,x2;
int a,b;
bool d,m;
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>x1>>x2;
	a=s2[2]-'0'-16;
	b=x2[2]-'0'-16;
	if(s1==x1) cout<<"1";
	else cout<<"0";
	if(s2[0]==x2[0] && s2[1]==x2[1] && s1==x1) cout<<"1";
	else cout<<"0";
	if(a<4 && b<4) d=1;
	if(a-b==1 || a-b==-1) m=1;
	if(a>=4 && b>=4){
		d=1;
	}
	if(s2[0]==x2[0] && s2[1]==x2[1] && s1==x1 && d) cout<<"1";
	else cout<<"0";
	if(s2[0]==x2[0] && s2[1]==x2[1] && s1==x1 && d && m) cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
