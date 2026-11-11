#include<bits/stdc++.h>
using namespace std;
#define long long int
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int num,viable_opt,a[500005],cnt=0;
	cin>>num>>viable_opt;
	for(int i=0;i<num;i++) 
		cin>>a[i];
	sort(a,a+num);
	int sr=0,staq[500005];
	for(int i=0;i<num;i++)
		sr+=a[i];
	sr=ceil(sr/num);
	for(int i=0;i<n;i++)
		staq[i]=max(sr,a[i])-min(sr,a[i]);
	sort(staq,staq+num)
	while(viable_opt!=0)
	{
		for(int i=num;i>0;i--)
		{
			if(viable_opt>=staq[i])
			{
				viable_opt-=staq[i];
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}//
