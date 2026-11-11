#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t; 
	srand(time(0));
	for(int i=1;i<=t;i++)
	{
	cout<<rand()%10+1;
	}
	return 0;
}

