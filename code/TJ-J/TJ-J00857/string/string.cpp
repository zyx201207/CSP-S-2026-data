 #include <bits/stdc++.h> 
using namespace std;
int main()
{
    cin.tie(0) ;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	long long num=0,ck=0;
	string b;
	for(int i=0;i<a;i++)
	{
		int v;
		string p;
		cin>>v>>p;
		for(int j=0;j<v;j++)
		{
			b+=p;
		}
		ck+=v;
	}
	for(int i=0;i<ck/2;i++)
	{
		if(b[i]!=b[ck-i])
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
