#include <iostream>
#include <algorithm>
#define aaa
using namespace std;
void caozuo(int arr[],int m,int n)
{
	int middle;
	middle = arr[n/2];
	int temp;
	while(m!=0)
	for(int i=0;i<n;i++)
	{
		if(m==0)	break;
		temp = middle-arr[i];
		if(temp<=m&&temp>0)
		{
			arr[i] = middle;
			m = m - temp;
		}
	}

}
int num(int arr[],int n)//查重  比谁多 
{
	vector<int> vec;//重复数字 
	
//	for(int i=0;i<vec.size();i++)	cout << vec[i] << " ";
//	cout << endl;
	
	for(int i=0;i<n-2;i++)
		for(int j=n-1;j>0;j--)
			if(arr[i]==arr[j])
			{
				vec.push_back(arr[j]);
			}
	int temp[vec.size()] = {0};
	for(int i=0;i<vec.size();i++)//vec的第几位 
		for(int j=0;j<n;j++)//查找数组
			if(arr[j]==vec[i])
				temp[i]++;
	int max = INT_MIN,tem;
	for(int i=0;i<vec.size();i++)
		if(max<temp[i])
		{
			max = temp[i];//最大重复数字数量 
		}
	return (max);
}
int main()
{
	#ifdef aaa 
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	#endif
	int n,m;
	cin >> n >> m;
	int arr[n] = {0};
	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	caozuo(arr,m,n);
	sort(arr,arr+n);
	int temp = num(arr,n);
	cout << temp;
	return 0;
}
/*-static-libgcc

5 5
1 9 8 4 2

*/
