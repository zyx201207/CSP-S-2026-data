#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string n,m;
cin>>n>>m;
sort(n.begin(),n.end());
reverse(n.begin(),n.end());
if(n%2==0)
{
	cout<<"1";
}

else cout<<"0";
return 0;
}
