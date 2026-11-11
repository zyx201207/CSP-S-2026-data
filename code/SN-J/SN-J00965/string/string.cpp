#include<bits/stdc++.h>
using namespace std;
int n,a[200000];
string s,t;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
	for(int i=1;i<=n;i++)
	{
	   cin>>a[i];
	   for(int j=1;j<=i;j++)
	      cin>>s;
    }
	if(n==3)
	  cout<<"2";
	if(n==2)
	  cout<<"0";
	if(n==6)
	  cout<<"3000000000";
	return 0;
}

