#include<iostream>
using namespace std;
long long n,m,q,p;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	while(n--)
	{
		cin>>q;
		p=max(q,p);
	}
	cout<<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

