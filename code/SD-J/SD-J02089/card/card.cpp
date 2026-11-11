#include<bits/stdc++.h>
using namespace std;
int a[1000010];
set <int >st;
int cnt[100010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		
		st.insert(a[i]);
		if(i==1) continue;
		for(int j=i-1;j<n;++j)
		{
			if(a[j]==a[i])
			{				for(int k=j;k<i;++k)
				{
					a[k]=0;
					if(k==i-1)
						a[k+1]=a[i];
				}
			}
		}
		if(i==n)
		{
			for(int j=1;j<=n;++j)
			{
				if(a[j]!=0)
				cnt[a[j]]++;
			}
		}
		for(int j=1;j<=st.size();++j)
			if(cnt[a[j]])
				cout<<cnt[a[j]]<<' ';
	}
		
	return 0;
}
