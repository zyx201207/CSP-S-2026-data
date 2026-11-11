#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	for (int i=1;i<=10000000;i++)
	{
		a=(i-1)*(i-1);
		b=i*i;
		c=(i+1)*(i+1);
		if (a+b==c)
		{
			cout<<i-1<<" "<<i<<" "<<i+1;
			cout<<endl;
		}
	}
	
	return 0;
}
