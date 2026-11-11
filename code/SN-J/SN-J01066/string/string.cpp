#include<bits/stdc++.h> 
using namespace std;
int a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	int i=1,j=n;
	long long num=0;
	while(i<j)
	{
		if(b[i] != b[j])
		{
			if(a[i]>a[j]) 
			{
				num+=a[j];
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else if(a[i]==a[j]) 
			{
				num+=a[i];
				a[i]=0;
				i++;
				a[j] = 0;
				j--;
			}
			else
			{
				num+=a[i];
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
			
		}
		if(b[i] == b[j])
		{
			if(a[i]>a[j]) 
			{
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else if(a[i]==a[j]) 
			{
				a[i]=0;
				i++;
				a[j] = 0;
				j--;
			}
			else
			{
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
			
		}
		
	}
	cout << num;
	return 0;
}
