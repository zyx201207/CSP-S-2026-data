#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
int num[500005];
int mius[500005];
int dp[500005];
int sp;


void spcheck()
{
	int t1=mius[2]-mius[1];
	int tm=m;
	int flag=1;
	//cout << t1 << endl;
	for(int i=2;i<n;++i)
	{
		int t2=mius[i+1]-mius[i];
		//cout << mius[i][i+1] << endl;
		if(t2 != t1)
		{
			flag=0;
			return;
		}
		else
			flag=1;
	}
	//cout << endl;
	if(flag)
		for(int i=1;i<=n;++i)
		{
			tm=tm-(t1*i);
			//cout << tm << endl;
			if(tm < 0)
			{
				//cout << endl;
				cout << i;
				sp=1;
				break;
			}
		}
	return;
} 

void oup()
{
	int max=-1;
	for(int i=1;i<=n;++i)
	{
		if(dp[i] > max)
			max=dp[i];		
	}
	cout << max;
	return;
}

void check()
{
	for(int i=1;i<=n;++i)
	{
		int t=0;
		int tm=m;
		for(int j=i;j>=1;--j)
		{
			int t1=mius[i]-mius[j];
			if((tm-t1) >= 0)
			{
				tm=tm-t1;
				//cout << tm << endl;
				t++;
			}
			else
				break; 
		}
		dp[i]=t;
		//cout << endl << dp[i] << endl;
	}
	oup();
	return;
}


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i)
		cin >> num[i];
	sort(num+1,num+1+n);
	for(int i=2;i<=n;++i)
		mius[i]=num[i]-num[i-1]+mius[i-1];
	spcheck();
	if(!sp)
		check();
	return 0;
}
