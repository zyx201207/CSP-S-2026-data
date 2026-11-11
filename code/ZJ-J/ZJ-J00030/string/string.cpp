#include<bits/stdc++.h>
using namespace std;
int a,b[200005];
char c[200005];
long long d=0,e=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int h=1;h<=a;h++)
	{
		cin>>b[h]>>c[h];
		d+=b[h];
	}
	long long e=0;
	int f=1,g=a;
	for(;;)
	{
		if(f==g)break;
		if(c[f]!=c[g])e+=min(b[f],b[g]);
		b[f]-=min(b[f],b[g]);
		b[g]-=min(b[f],b[g]);
		if(b[f]==0)f++;
		if(b[g]==0)g--;
	}
	cout<<e;
	return 0;
}