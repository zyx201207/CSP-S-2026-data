#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("treval.in","r",stdin);
  freopen("treval.out","w",stdout);
  string s={};
  long long n,a,sum=0;
  char b;
  cin>>n;
  for(long long i=0;i<n;i++){
	  cin>>a>>b;
	  for(long long j=0;j<a;j++){
		  s+=b0;
	  }
	  sum+=a;
  }
  long long huan=0;
  for(long long i=0;i<sum/2;i++){
	if(s[i]!=s[sum-i-1])
		huan++;
	}
  cout<<huan;
  fclose(stdin);
  fclose(stdout);
  return 0;
 }
