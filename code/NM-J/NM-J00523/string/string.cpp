#include<bits/stdc++.h>
using namespace std;
int q[1000010];
string j[1000010];
bool y[1000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,he=0;
	cin>>n;
	if(n==1) {cout<<0;return 0;} 
	for(int i=1;i<=n;i++)
	{
		cin>>q[i]>>j[i];
		if(j[i]==j[i-1]) y[i]=true;
		if(y[i]==true) he++;
	}
	if(he==n) cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
