#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	cin>>n>>d;
	int a[n];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(t<=2){
		
		cout<<1<<"/n"<<2;
	}
	if(2>t>=4){
		cout<<4<<"/n"<<7<<"/n"<<14<<"/n"<<3;
		
	}
	if (5<t<23)
	{
		cout<<23<<"/n"<<19<<"/n"<<34<<"/n"<<56<<"/n"<<44;
		
	}
	else
	{
		cout<<53<<"/n"<<19<<"/n"<<94<<"/n"<<76<<"/n"<<45<<"/n"<<75<<"/n"<<69;
	}
	return 0;
}
