#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt,ans_1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=n/2+1;
	    for(int i=1;i<ans;i++)
	    {
			cnt+=a[ans]-a[i];
			ans_1+=2;
			if(cnt>m+1)
			{
				cnt=cnt-(a[ans]-a[i]);
				ans_1-=2;
				break;
			}
		}
	cout<<ans_1+1<<endl;
	return 0;
} 