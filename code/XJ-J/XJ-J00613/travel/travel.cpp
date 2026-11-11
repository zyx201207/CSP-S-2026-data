#include<bits/stdc++.h>
using namespace std;
char a[3],b[3];
int x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>x;
    for(int i=0;i<3;i++) cin>>a[i];
    cin>>y;
    for(int i=0;i<3;i++) cin>>b[i];
	if(x==y) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0] && a[1]==b[1]) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(a[2]>='A' && a[2]<='C' && b[2]>='A' && b[2]<='C'|| a[2]>='D'&&a[2]<='F' && b[2]>='D' && b[2]<='F')
	cout<<1;
	else {
		cout<<"00";
		return 0;
	}	
	if(a[2]=='F' && b[2]=='D' || a[2]=='D' && b[2]=='F')
	{
		cout<<1;
		return 0;
	}
	if(a[2]+1==b[2] || a[2]-1==b[2])
	{	
		cout<<1;
	}
	else 
	{
		cout<<0;
		return 0;
	}
	return 0;
}