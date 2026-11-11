#include <iostream>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	
	//freopen("string.out","w",stdout);
	long long n;
	string s="";//空字符串
	long long cnt =  0;//统计现在是第多少个 光标 
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		long long a;
		cin>>a;
		long long c;
		cin>>c;
		for(int j = 1;j<=a;j++)
		{
			s[cnt]=c;
			cnt += 1;
			
			
		}
	}
	long long sum = 0;//统计最少修改次数 
	long long que = s.size();
	for(int i = 0;i<=que/2;i++)
	{
		if(s[i]!=s[que-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
 } 

 
