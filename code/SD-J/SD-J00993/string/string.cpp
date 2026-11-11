#include<iostream>
using namespace std;
int a[1000100];
char c[1000100];
long long cnt=0;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i] >> c[i];
	int i=1,j=n;
	while(i<=j)
	{
		while(a[i]>a[j]&&i!=j)
		{
			if(c[i]!=c[j]) cnt+=a[j];
			a[i]-=a[j];
			j--;
		}
		if(c[i]!=c[j]) cnt+=a[i];
		a[j]-=a[i];
		i++;
	}
	cout << cnt;
	return 0;
}
