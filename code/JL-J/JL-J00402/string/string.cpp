#include <iostream>
using namespace std;
unsigned long long ans;
pair<int,char> arr[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int j;
	for(j = 0; j < n; j++)
	{
		cin >> arr[j].first >> arr[j].second;
	}
	for(int i = 0;j>=i;)
	{
		if(arr[i].second==arr[j].second)
		{
			if(arr[i].first>arr[j].first)
			{
				arr[i].first-=arr[j].first;
				j--;
			}
			else if(arr[i].first==arr[j].first)
			{
				i++;
				j--;
			}
			else
			{
				arr[j].first-=arr[i].first;
				i++;
			}
		}
		else
		{
			if(arr[i].first>arr[j].first)
			{
				ans+=arr[j].first;
				arr[i].first-=arr[j].first;
				j--;
			}
			else if(arr[i].first==arr[j].first)
			{
				ans+=arr[j].first;
				i++;
				j--;
			}
			else
			{
				ans+=arr[i].first;
				arr[j].first-=arr[i].first;
				i++;
			}
		}
	}
	cout << ans;
	return 0;
}
