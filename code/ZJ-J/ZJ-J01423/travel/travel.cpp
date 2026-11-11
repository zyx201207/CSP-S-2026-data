#include<bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,INF=INT_MAX;
string c1,s1,c2,s2;
int a1,a2,b1,b2;
char a3,b3;
signed main()
{
  AKIOI;
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin>>c1>>s1>>c2>>s2;
  a1=(c1[0]-'0')*10+c1[1]-'0';
  b1=(c2[0]-'0')*10+c2[1]-'0';
  if(a1==b1)
  {
  	cout<<1;
  	a2=(s1[0]-'0')*10+s1[1]-'0';
    b2=(s2[0]-'0')*10+s2[1]-'0';
    if(a2==b2)
    {
      cout<<1;
      a3=s1[2];
      b3=s2[2];
      if(a3<='C' && b3<='C')
      {
      	cout<<1;
      	if(abs(a3-b3)==1) cout<<1;
      	else cout<<0;
	  }
	  else if(a3>='D' && b3>='D')
	  {
	  	cout<<1;
	  	if(abs(a3-b3)==2) cout<<1;
      	else cout<<0;
	  }
	  else cout<<"00";
	}
	else
	{
	  cout<<"000";
	}
  }
  else
  {
  	cout<<"0000";
  }
  return 0;
}
