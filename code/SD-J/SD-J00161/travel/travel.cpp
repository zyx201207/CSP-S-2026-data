#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
bool xl(char x,char y)
{
	if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F') return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,a,b;
	cin>>n>>a>>m>>b;
	if(n!=m||n==m&&a==b){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	if(!(a[0]==b[0]&&a[1]==b[1])){
		cout<<"000";
		return 0;
	}
	else cout<<1;
	char x=a[2],y=b[2];
	if(!(x>='D'&&y>='D'||x<'D'&&y<'D')){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	if(!(xl(x,y)||xl(y,x))){
		cout<<0;
		return 0;
	}
	else cout<<1;
	return 0;
} 
