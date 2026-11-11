#include<bits/stdc++.h>
using namespace std;
long long a,b,c,t,w,l,d[200001][3],o,u[200001];
char e;
string f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b>>e;
		d[i][1]=b;
		d[i][2]=e-'a';
	}
	t=1;
	w=a;
	while(t<w)
	{
		if(d[t][1]<d[w][1])
		{
			d[w][1]-=d[t][1];
			if(d[t][2]!=d[w][2])
				l+=d[t][1];
			t++;
		}
		else
		{
			
			d[t][1]-=d[w][1];
			if(d[t][2]!=d[w][2])
				l+=d[w][1];
			w--;
		}
	}
	cout<<l;
	return 0;
 } //AC
