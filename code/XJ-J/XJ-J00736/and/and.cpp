#include<bits/stdc++.h>
using namespace std;

int tong[10000];
int arr[1000000];
int main(){
	int n,m;
	cin>>n>>m;
	int num;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			num=j;
			for(int q=j+1;q<=n;q++);
			{
				if(arr[q]==arr[j])
				{
					num=q;
					break;
				}
			}
			for(int b=num;b<=n;b++)
				tong[arr[b]]++;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<tong[i];
	return 0;
}