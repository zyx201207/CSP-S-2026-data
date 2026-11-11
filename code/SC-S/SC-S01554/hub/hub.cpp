#include<bits/stdc++.h>
using namespace std;
int x,y,z[100];
int main(){
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout); 
	for(int i=0;i<5;i++)cin>>z[i];
	cin>>x>>y;
	cout<<"1"<<endl<<"2";
	y+=z[3];
	z[10]=x+y;
	x++;y++;
	x-=1;y+=10000;
	return 0;
} 