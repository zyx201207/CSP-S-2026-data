#include<bits/stdc++.h>
using namespace std;
char a[10000],c[10000];
int n,b[10000],s=0,p=0,l;
int main(){
		freopen("string.in","r",stdin);
	    freopen("string.out","w",stdout);
	     cin>>n;
		for(int i=1;i<=n;i++)
	     {   cin>>b[i]>>a[i];
	           p=p+b[i];
	          for(int j=1;j<=i;j++)
	          {
	          	 c[i]=b[i];
			  }
		     }
		for(int i=1;i<=p;i++)
		{   if(c[i]!=c[p-i])
			s++;
		}
		cout<<s/2;
}               
