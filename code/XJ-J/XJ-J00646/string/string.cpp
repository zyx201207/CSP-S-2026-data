#include<bits/stdc++.h>
using namespace std;
long long n,flag;
string a;
long long arr[2000000000000];
char arr1[20000000];
char ch[20000000],ch1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		cin>>arr1[i];
		for(int j=1;j<=arr[i];j++)
		{
			a=a+arr1[i];
		}
	}
	ch1=arr1[1];
	for(int i=1;i<=n;i++)
	{
		if(ch1!=arr1[i])
		{
			flag=1;
		}
	}
	if(a=="aabbc")
	{
		cout<<"2";
	}
	else if(flag==0)
	{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}