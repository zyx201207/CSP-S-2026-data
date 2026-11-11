#include <bits/stdc++.h>
using namespace std;
string a;
int d [300010];
int main()
{
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	int n,m;
	cin>>n>>m;
	char c;
	for(in i=1;i<=n;i+=)
	{
		cin>>a[i];
	}
	int n1=n,k=1;
	while(n1--)
	{
	    string s;
		for(int i=k;i<=n;i++)
		{
			int t=s.find(cher(a[i]+'0'))
			if(t!=-1)
		   {
			    s.erase(t,i-t+1);
		    }
		    s+=a[i];
			s+=char(a[i]+'0');
	    }  
	    for(int i=0;i<s.size();i++)
	    {
	    	d[s[i]-'0']++;
		}
	    k++
   }
   for(int i=1;i<=m;i++)
   {
   	   cout<<d[i]<<" ";
   }	   
	retur 0;
	
	
}


