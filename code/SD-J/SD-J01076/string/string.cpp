#include <iostream> 
using namespace std;
char a[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int pos=0; 
	for(int i=1;i<=n;i++)
	{
		int num;
		char x;
		cin >> num >> x;
		for(int j=1;j<=num;j++)
		{
			a[pos+j]=x;
		}
		pos+=num;
	}
	int ans=0; 
	for(int i=1;i<=pos/2;i++)
	{
		if(a[i]!=a[pos-i+1])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
