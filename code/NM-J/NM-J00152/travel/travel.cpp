#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int i,j,k,l;
int ab_s(int s)
{
	if(s<0)return -s;
	else return s;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
	i=j=k=l=0;
	if(a[0]==c[0] and a[1]==c[1])
	{
		i=1;
		if(b[0]==d[0] and b[1]==d[1])
		{
			j=1;
			if((b[2]<='C' and d[2]<='C')or(b[2]>'C' and d[2]>'C'))
			{
				k=1;
				if(ab_s(b[2]-d[2])==1 or (b[2]=='D' and d[2]=='F')or(d[2]=='D' and b[2]=='F'))
				l=1;
				else l=0;
			}
			else k=0;
		}
	    else j=0;
	}
	else i=0;
	cout<<i<<j<<k<<l;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
