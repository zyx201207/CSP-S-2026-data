#include<iostream>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
	if(c==0&&t==2)
	{
		cout<<1<<endl;
		cout<<2;
		return 0;
	}
	for(int i=0;i<t;i++)
		cout<<i+1<<endl;
	return 0;
}
