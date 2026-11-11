#include <bits/stdc++.h>
using namespace std;
const long long MAXN=100000005;
long long a[MAXN];
int main()
{
  string b[30];
  long long n;
  cin>>n;
  long long k=0;
  string s[100000];
 for(int i=1;i<=n;i++)
  {
  	cin>>a[i]>>b[i];
	  k=k+a[i];}
  	 for(int i=1;i<=n;i++){
  	for(int j=1;j<=a[i];j++)
  	{
  	 s[j]=b[i];
  		 }
  	}
  int  sum=0;
  
	for(int i=0;i<=k/2;i++){
	if(s[i]!=s[k+1-i])
	{
		sum++;
	}
}
	
	cout<<sum;
	return 0;
}

