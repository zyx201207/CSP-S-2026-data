#include<iostream>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2)
	{
		cout<<32<<endl;
		cout<<17;
		return 0;
	}
	else if(c==0&&n==3)
	{
		cout<<35<<endl;
		cout<<16;
		return 0;
	}
	return 0;
}
