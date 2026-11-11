#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int q=0,w=0,e=0,r=0;
	if(a==c) q=1;
	if(q&&(b[0]==d[0])&&(b[1]==d[1])) w=1;
	bool le=false;
	if((b[2]>='A' && b[2]<='C') && (d[2]>='A' && d[2]<='C')) le=true;
	bool ri=false;
	if((b[2]=='D' || b[2]=='F') && (d[2]=='D' && d[2]=='F')) ri=true;
	if(w&&(le||ri)) e=1;
	if(e&&(abs((int)(b[2]-d[2]))==1)) r=1;
	cout<<q<<w<<e<<r<<endl;
	return 0;
}
/*
08:50

all subtasks were ACed

luogu 1842302

JL-J00529
*/