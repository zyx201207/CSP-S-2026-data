#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,e=0,i=0;
	char f,g,h;
	cin>>f>>a;
	if(f=='1')
	a+=10;
	cin>>f>>b>>g;
	if(f=='1')
	b+=10;
	cin>>f>>c;
	if(f=='1')
	c+=10;
	cin>>f>>d>>h;
	if(f=='1')
	d+=10;
	if(c!=a){
		cout<<"0000"<<endl;
		return 0;
	}
	else{
		cout<<1;
		if(b==d)
		cout<<1,e=1;
		else
		cout<<0;
		if(((g<='C'&&h<='C')||(g>'C'&&h>'C'))&&e)
		cout<<1,i=1;
		else
		cout<<0;
		if((int(g)+1==int(h)||int(g)==int(h)+1)&&i)
		cout<<1;
		else
		cout<<0;
	}
	return 0;
}
