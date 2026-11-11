#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[4];
	string b,c;
	cin>>a[1]>>b>>a[2]>>c;
	if(a[1]==a[2])cout<<1;
	else {cout<<0<<0<<0<<0;return 0;}
	if(int(b[0]+b[1])==int(c[0]+c[1]))cout<<1;
	else {cout<<0<<0<<0;return 0;}
	if(b[2]<68&&c[2]<68)cout<<1;
	else if(b[2]>67&&c[2]>67){cout<<11;return 0;}
	else {cout<<0<<0;return 0;}
	if(max(int(b[2]),int(c[2]))%min(int(b[2]),int(c[2]))==1)cout<<1;
	else cout<<0;
	return 0;
}