#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) ans++;
	if(ans==1&&(b[0]-'0'*10+b[1]-'0')==(d[0]-'0'*10+d[1]-'0')) ans++;
	if(ans==2&&(!(b[2]=='C'&&d[2]=='D')||(d[2]=='C'&&d[2]=='D')))ans++;
	if(ans==3&&(b[2]+1==d[2]||d[2]+1==b[2])) ans++;
	for(int i=1;i<=ans;i++)
    {
    	cout<<1;
	}
	for(int i=0;i<4-ans;i++)
	{
		cout<<0;
	}
	return 0;
}