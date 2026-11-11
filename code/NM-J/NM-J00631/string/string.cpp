#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main()
{
  string s,s1;
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  long long int n,w=0,sum=0;
  cin>>n;
  string c;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i]>>c[i];
    for(int j=1;j<=a[i];j++)
      s=s+c[i];
  }
  for(int i=s.size();i>=0;i--)
  {
    s1=s1+s[i];
  }
  cout<<s1;
  long long int l=s.size(),l1=l;
  for(int i=1;i<=n+1;i++)
    if(s1[i]==s[i])  w++;
    if(w==n)
    {
      cout<<0;
      return 0;
    }
  if(l%2==0)
  {
    while(l1>=0)
    {
     if(s1[0.5*l1]!=s1[0.5*l1-1])    sum++;
     l1=l1-2;
    }
  }
  if(l%2!=0)
  {
    while(l1>=0)
    {
     if(s1[0.5*(l1+1)-1]!=s1[0.5*(l1+1)+1])    sum++;
     l1=l1-2;
    }
  }
  cout<<sum;
  return 0;
}
