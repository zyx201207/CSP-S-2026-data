#include<bits/stdc++.h> 
using namespace std;
int main()
{freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,a[200005],cnt=0;
char b[200005];
string c;
cin>>n;
for(int i=0;i<n;i++)
{    cin>>a[i]>>b[i];
}
for(int i=0;i<n;i++)
{    for(int j=1;j<=a[i];j++)
     {    c+=b[i];
	 }
}	
if(c.length()%2==1)
{    for(int i=0;i<(c.length()-1)/2;i++)
     {    for(int j=c.length()-1;j>(c.length()-1)/2;j--)
          {    if(i+j==c.length()-1)
               {    if(c[i]!=c[j])
                    {    cnt++;
					}
			   }
               
		  }
	 }
       
}
else
{    for(int i=0;i<=(c.length()-1)/2;i++)
     {    for(int j=c.length()-1;j>(c.length()-1)/2;j--)
          {    if(i+j==c.length()-1)
               {    if(c[i]!=c[j])
                    {    cnt++;
					}
			   }
               
		  }
	 }
       
}
cout<<cnt;
return 0;
}
