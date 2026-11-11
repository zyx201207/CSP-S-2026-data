#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
long long n,m,a[N],cha[N],cnt,num[N][2],maxnum=1;
//cha[i]:a[i]-a[i-1]

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	cnt=m;
	memset(num,0,sizeof(num));
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<=0) num[a[i]][0]++;
		else num[a[i]][1]++;//记录为a[i]大小的数有几个
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++)
	{
		cha[i-1]=a[i]-a[i-1];
	}

	//输出测试
	//for(long long i=1;i<=n;i++)
	//{
		//cout<<"a:"<<a[i-1]<<endl;
	//}
	//for(long long i=1;i<=n;i++)
	//{
		//if(a[i-1]<=0)	cout<<"num:"<<num[a[i-1]][0]<<" "<<"a[i-1]:"<<a[i-1]<<endl;
		//else cout<<"num:"<<num[a[i-1]][1]<<" "<<"a[i-1]:"<<a[i-1]<<endl;
	//}
	//for(long long i=1;i<n;i++)
	//{
		//cout<<"cha:"<<cha[i-1]<<endl;
	//}

	if(n<=5000)//1-5测试点
	{
		for(long long i=1;i<n;i++)
		{
			int opa,opb;
			if(a[i-1]<=0) opa=0;
			else opa=1;
			if(a[i]<=0) opb=0;
			else opb=1;
			for(int k=num[a[i-1]][opa];k>=1;k--)
			{
				if(cnt-cha[i-1]*k>=0)
				{
					cnt=cnt-cha[i-1]*k;
					num[a[i-1]][opa]=num[a[i-1]][opa]-k;
					//cout<<num[a[i]][opb]<<endl;
					num[a[i]][opb]=num[a[i]][opb]+k;
					maxnum=max(maxnum,num[a[i]][opb]);
					//cout<<"cnt:"<<cnt<<" "<<"k:"<<k<<" "<<"i:"<<i<<" maxnum:"<<maxnum;
					//cout<<" num[a[i-1]][opa]:"<<num[a[i-1]][opa]<<" num[a[i]][opb]:"<<num[a[i]][opb]<<endl;
					//使能量为a[i-1]的尽可能多的水晶到a[i]
					break;
				}
				//将i水晶到达i-1水晶的操作数：cha[i]
			}
			if(cnt==0) break;
		}
	}

	cout<<maxnum<<endl;

	return 0;
}
//5 5 1 2 4 8 9:3
//5 8 -3 -1 2 2 7:4
//5 7 1 5 6 10 100:3
//5 4 1 98 99 100 101:3
//5 7 1 98 99 100 101:4
//5 4 101 102 102 102 102:5
//10 3 1 1 1 1 1 1 1 2 2 2:7
//Oct31==Dec25?
//测试3：3845
//测试4：315275
