#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int cnt=0;
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=0;i<=1;i++)
    {
        if(a[i]!=c[i])
        {
			cout<<"0000";
		    return 0;
	    }
    }
    cout<<1;
	for(int i=0;i<=1;i++)
    {
        if(b[i]!=d[i])
        {
			cout<<"000";
		    return 0;
	    }
    }
    cout<<1;
		 if(d[2]=='A'||d[2]=='B'||d[2]=='C')
		 {
			  if(b[2]=='A'||b[2]=='B'||b[2]=='C')
			  {
				  cout<<1;
				  if(d[2]=='B'||b[2]=='B')
				  {
					  cnt=1;
				  }
			  }
			  else
			  {
				  cout<<0;
			  }
	     }
	     else
	     if(d[2]=='E'||d[2]=='F')
		 {
			  if(d[2]=='E'||d[2]=='F')
			  {
				  cout<<1;
				  cnt=1;
		      }
		      else
		      {
				  cout<<0;
			  }
	     }
	     else
	     cout<<0;
    if(cnt==1)
    {
		cout<<1;
    }
    else
    {
		cout<<0;
	}
	return 0;
}
