#include<bits/stdc++.h>
using namespace std;
struct g
{
	int c,p;
	char z;
}r,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;
	cin>>rc>>rz>>xc>>xz;
	r.c=(rc[0]-'0')*10+(rc[1]-'0');
	r.p=(rz[0]-'0')*10+(rz[1]-'0');
	r.z=rz[2];
	x.c=(xc[0]-'0')*10+(xc[1]-'0');
	x.p=(xz[0]-'0')*10+(xz[1]-'0');
	x.z=xz[2];
	if(r.c==x.c)
	{
		cout<<1;
		if(r.p==x.p)
		{
			cout<<1;
			if(((r.z=='A'||r.z=='B'||r.z=='C')&&(x.z=='A'||x.z=='B'||x.z=='C'))||((r.z=='D'||r.z=='F')&&(x.z=='D'||x.z=='F'))) 
			{
				cout<<1;
				if((r.z=='A'&&x.z=='B')||(x.z=='A'&&r.z=='B')||(r.z=='B'&&x.z=='C')||(r.z=='C'&&x.z=='B')||(r.z=='D'&&x.z=='F')||(r.z=='F'&&x.z=='D'))
				cout<<'1';
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000"; 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
