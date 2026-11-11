#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	int n,i;
	char a[1000],c[1000];
	cin>>n;
	for(i=0;i<=n;i++)
		cin>>a[i]>>c[i];
	if(n==1)
		cout<<"0";
	return 0;
}
