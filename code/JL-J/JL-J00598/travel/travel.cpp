#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool x=true,y=true;
	string n,m,q,w;
	cin>>n>>m>>q>>w;
	if(m[2]=='D'||m[2]=='F'){
	x=false;
	}
	if(w[2]=='D'||w[2]=='F'){
	y=false;
	}
//	cout<<x<<' '<<y;
	if(n!=q)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	else 
    {
		cout<<1;
		if(m[0]==w[0]&&m[1]==w[1])
		{
			 cout<<1;
			 if(x==y)
		      {
			  cout<<1;
			   if(char(m[2]+1)==w[2]||char(m[2]-1)==w[2])
			   {
				  cout<<1;
			   }
			   else
			   {
				   cout<<0;
			   }
		      }
			  else
			  {
			 	cout<<"00";
			  }
		}
		else
		{
			cout<<"000";
		}
	}
	cout<<endl;
	return 0;
}

