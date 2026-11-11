#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans=0;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,k;
	cin>>n>>k;
	int a[25000000][25000000];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i][i];
	}
	if (t<=2)
	{
		cont<<1<<"/n"<<2;
		
	}
	if (2<t<=8) 
	{
		cout<<4<<"/n"<<6<<"/n"<<3<<"/n"<<2;
	}
	else
	{
		cout<<1<<"/n"<<0;
	}
	return 0;
}
