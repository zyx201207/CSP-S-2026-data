#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
char b[N];
bool flag=true;
int main()
{freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,sum=0;
cin>>n;
for(int i=0;i<n;i++)
	{
	cin>>a[i];
	sum=sum+a[i];
	cin>>b[i];
	
	if(b[i]!=b[i-1])
		{flag=false; 
		}	
	}
if(flag==true)
{cout<<0;
return 0;
}
else
	{
	if(sum<a[0])
		{cout<<sum-a[0];
		}
	else if(a[0]==sum/2)
		{cout<<a[0];
		}
	else{cout<<sum-a[0];
		}
	}
return 0;
} 
