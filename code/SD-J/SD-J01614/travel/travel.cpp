 #include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[2],b[2];
	cin>>a[0]>>a[1]>>b[0]>>b[1];
	if(a[0]==b[0]) 
	{
		cout<<1;
		if(a[1][0]==b[1][0]&&a[1][1]==b[1][1])
	    {
		cout<<1;
		if(a[1][2]>='A'&&a[1][2]<='C'&&b[1][2]>='A'&&b[1][2]<='C') 
		{
			cout<<1;
			if(a[1][2]-1==b[1][2]||a[1][2]+1==b[1][2]) cout<<1;
			else cout<<"0";
		}
		else if((a[1][2]=='D'||a[1][2]=='F')&&(b[1][2]=='D'||b[1][2]=='C')) 
		{
			cout<<"11";
		}
		else cout<<"00";
	    }
	    else cout<<"000";
	}
	else cout<<"0000";
	return 0;//easy!AWA
 } 
