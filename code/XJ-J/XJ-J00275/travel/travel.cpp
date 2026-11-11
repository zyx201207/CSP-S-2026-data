#include <iostream>
using namespace std;
int ax,ar;
string bx,br;
int main(){
	freopen( "travel.in","r",stdin );
	freopen("travel.out","w",stdout);
	cin>>ax>>bx>>ar>>br;
	if( ax==ar )
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if( bx==br )
	{
		cout<<11;
	}
	else
	{
		cout<<00;
	}
	if( bx==br )
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}