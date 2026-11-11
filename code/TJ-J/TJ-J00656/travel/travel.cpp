#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c[6];
	string a,A,b,B;
	cin>>a>>A>>b>>B;
	if(a==b)
	{
		c[0]=1;
	}
	else
	{
		c[0]=0;
		cout << "0000";
		return 0;
	}
	cout<<c[0];
	if(c[0]==1&&A[0]==B[0]&&A[1]==B[1])
	{
		c[1]=1;
	}
	else
	{
		c[1]=0;
	}
	cout << c[1];
	
	if(c[1]==1&&('A'<=char(A[2])&&char(A[2])<='C'&&'A'<=char(B[2])&&char(B[2])<='C'))
	{
		c[2]=1;
	}
	else if(c[1]==1&&('D'<=char(A[2])&&char(A[2])<='F'&&'D'<=char(B[2])&&char(B[2])<='F'))
	{
		c[2]=1;
		c[3]=1;
		
	}
	else
	{
		c[2]=0;
		
	}
	cout << c[2];
	if(c[2]==1&&((char(A[2])=='A'&&char(B[2])=='B')||(char(A[2])=='B'&&char(B[2])=='A')||(char(A[2])=='B'&&char(B[2])=='C')||(char(A[2])=='C'&&char(B[2])=='B')))
	{
		cout << c[2];
		c[3]=1;
		
	}
	else
	{
		c[3]=0;
	}
	cout << c[3];

	return 0;
}
