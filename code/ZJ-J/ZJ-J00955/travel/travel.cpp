#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	if(a==c)f1=1;
	else f1=0;
	if(b[0]==d[0] && b[1]==d[1] && f1==1)f2=1;
	else f2=0;
	if(((b[2]<='C' && d[2]<='C')||(b[2]>='D' && d[2]>='D'))&& f1==1 && f2==1)f3=1;
	else f3=0;
	if(f1==0 || f2==0 || f3==0)f4=0;
	else{
		int x=0;
		x=b[2]-d[2];
		if(x==1 || x==-1)f4=1;
		else f4=0;
	}
	cout<<f1<<f2<<f3<<f4;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}