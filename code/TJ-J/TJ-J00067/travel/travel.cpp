#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b)
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	int p=0;
	if(a==b)
	{
		if(x[0]==y[0]&&x[1]==y[1])
		{
			p=1;		
		}
	}
		cout<<p;
		int q=0;
		if(a==b){
		if(x[0]==y[0]&&x[1]==y[1])
		{
			if((x[2]=='A'&&y[2]=='B')||(x[2]=='A'&&y[2]=='C')||(x[2]=='B'&&y[2]=='C')||(x[2]=='B'&&y[2]=='A')||(x[2]=='C'&&y[2]=='A')||(x[2]=='C'&&y[2]=='B')||(x[2]=='D'&&y[2]=='F')||(x[2]=='F'&&y[2]=='D'))
			{
				q=1;
			}
		}
	}
		cout<<q;
		int z=0;
		char c=x[2];
		char d=y[2];
		if(a==b)
		{
		if(x[0]==y[0]&&x[1]==y[1]){
		if((c!='D'&&d!='C')||(c!='C'&&d!='D'))
		{
		if(c-d==1||d-c==1)
		{
			z=1;
		}
	}
}
}
		cout<<z;
	return 0;
	
}
