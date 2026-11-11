#include<bits/stdc++.h>
using namespace std;
int s,t,u,v;
string a,b,c,d;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int w=10*(a[0]-'0')+(a[1]-'0');
	int x=10*(c[0]-'0')+(c[1]-'0');
	int y=10*(b[0]-'0')+(b[1]-'0');
	int z=10*(d[0]-'0')+(d[1]-'0');
	if(b[2]=='F') b[2]='E';
	if(d[2]=='F') d[2]='E';
	if(w==x) s=1;
	if(s==1 and y==z) t=1;
	if(s==1 and t==1 and ((b[2]<='C' and d[2]<='C') or (b[2]>='D' and d[2]>='D'))) u=1;
	if(s==1 and t==1 and u==1 and abs((b[2]-'A')-(d[2]-'A'))==1) v=1;
	cout<<s<<t<<u<<v<<"\n";
	
	return 0;
}
