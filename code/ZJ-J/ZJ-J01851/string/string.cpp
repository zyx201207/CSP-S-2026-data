#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long len,mx;
struct node
{
  long long c;
  char s;
}a[200005];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i].c>>a[i].s;
    len+=a[i].c;
    for(int j=1;j<=a[i].c;j++)
      s+=a[i].s;
  }
  for(int i=0,j=len-1;i<len/2;i++,j--)
    if(s[i]!=s[j])mx++;
  cout<<mx;
  return 0;
}
