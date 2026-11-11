#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=1;
int a[200005];
int cnt[200005];
int t[30][200005];
bool er[200005][30];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//cout<<a[i]<<' ';
		if(a[i]%2)
		{
			cnt[0]++;
			t[0][cnt[0]]=a[i];
		}
		for(int j=1;j<=30;j++)
		{
			if((a[i]>>j)%2==1)
			{
				er[i][j]=1;
				cnt[j]++;
				t[j][cnt[j]]=i;
			}
		}
		//cout<<endl;
	}
	//cout<<endl;
		
	a[0]=1;
	for(int i=30;i>=0;i--)
	{
		int sum=0;
		if(cnt[i]==m)
		{
			ans=a[t[i][1]];
			for(int j=1;j<=cnt[i];j++)
			{
				int xb=t[i][j];
				ans=ans&a[xb];
			}
			cout<<ans;
			return 0;
		}	
		else if(cnt[i]>m)
		{
			int l=cnt[i];
			//i--;
			int w=i-1;
			while(w>=0)
			{
				//cout<<1<<endl;
				//cout<<sum<<endl;
				if(sum<m&&w!=i-1)
				{
					cout<<ans;
					return 0;
				}
				sum=0;
				ans=a[t[i][1]];
				//cout<<endl;
				//cout<<ans<<endl;
				for(int j=1;j<=l;j++)
				{
					int xb=t[i][j];
					ans=ans&a[xb];
					sum+=er[xb][w];
					if(er[xb][w]==0) t[i][j]=0;
				}
				if(sum==m)
				{
					cout<<ans;
					return 0;
				}
				w--;
			}
			
		}
	}
	return 0;
}

