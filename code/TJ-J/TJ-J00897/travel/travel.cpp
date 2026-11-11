#include<iostream> 
using namespace std;
int main()
{
	int as=0,ws=0,ay=0,w=0,n=0,p=0,q=0;
	string a,c,b,d;
	cin>>a;
	cin>>b;
	cin>>c;
    cin>>d;
    for(int i=1;i<=2;i++)
	{
		if(a[i]==c[i])
        {
			as++;
		}
    }
	if(as==2)
	{
		w=1;
	}
	if(as==2)
	{
		for(int i=0;i<=1;i++)
	    {
	    	if(b[i]==d[i])
	    	{
	    		ws++;
			}
		}
	}
	if(ws==2)
	{
		n=1;
		if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))
		{
			p=1;
		}
	}
	if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))
	{
	    q=1;
	}
	cout<<w<<n<<p<<q;
	return 0;
}
