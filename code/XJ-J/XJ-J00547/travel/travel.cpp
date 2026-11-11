#include <iostream>
using namespace std;
int c1,c2;
int main()
{
	freopen("travel.in","m",stdin);
	freopen("travel.out", "r",stdout);
	char s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans=110;
	if(c1==c2)
	{
		ans+=1000;
    }
    
	cout<<ans;
	return 0;
}