#include<bits/stdc++.h>
using namespace std;

char str_[1000000005];
int list1[200005];
char list2[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; 
	long long long1 = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> list1[i] >> list2[i];
		long1 += list1[i];
	}
	int o = 1;
	long long num = 0;
	while(o < n)
	{
		if(list1[o] > list1[n])
		{
			if(list2[o] == list2[n])
			{
				list1[o] -= list1[n];
				n--;
			}
			else
			{
				num += list1[n];
				list1[o] -= list1[n];
				n--;
			}
		}
		else if(list1[o] < list1[n])
		{
			if(list2[o] == list2[n])
			{
				list1[n] -= list1[o];
				o++;
			}
			else
			{
				num += list1[o];
				list1[n] -= list1[o];
				o++;
			}
		}
		if(list1[o] == list1[n])
		{
			if(list2[o] == list2[n])
			{
				o++;
				n--;
			}
			else
			{
				num += list1[o];
				o++;
				n--;
			}
		}	
	}
	cout << num;
	return 0;
 } 
