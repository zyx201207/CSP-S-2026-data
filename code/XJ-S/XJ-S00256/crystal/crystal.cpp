#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int cnt = m;
	int v =0;
	int j=1;
	while(j<=n);
	{
		if(cnt==0)
		{
			j++;
		}
		int num=1;
		int sum=a[j]+cnt;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=sum)
			{
				num+=1;
			}
		}
		if(v<num)
		{
			v=num;
		}
		cnt--;
		
	}
	cout << v;
	return 0;
}
