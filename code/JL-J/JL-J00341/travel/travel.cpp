#include <iostream>
using namespace std;
int main(){
	int a,b;
	char a1[4],b1[4];
	cin>>a;
	freopen("travel.in","r",stdin);
	for(int i=1;i<=4;i++)
		cin>>a1[i];
	cin>>b;
	for(int i=1;i<=4;i++)
		cin>>b1[i];
	if(a==b)
		cout<<1;
	else
		cout<<0;
	
	if(a1[2]==b1[2])
		cout<<1;
	else
		cout<<0;
	if((a1[3]>='D' && b1[3]<='C') || (a1[3]>='C' && b1[3]<='D'))
		cout<<0;
	else
		cout<<1;
	if(a1[3]==b1[3])
		cout<<0;
	else
		if(a1[3]==b1[3]+1 || a1[3]+1==b1[3])
			cout<<1;
		else
			cout<<0;
	freopen("travel.out","w",stdin);
	return 0;
}
