/*
	50pts or more
	luogu 1842302
	1430~1638
*/
#include<bits/stdc++.h> 
using namespace std;
const long long maxn=5e5+5;
int a[maxn];
int dif[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int mina=INT_MAX;
	int maxa=INT_MIN;
	for(int i=0;i<n;i++) //n
	{
		cin>>a[i];
		mina=min(mina,a[i]);
		maxa=max(maxa,a[i]);
	}
	if(2*n*(maxa-mina)<=1e8)//O(2*|ai|*n)  #1~7
	{
		//cout<<maxa<<' '<<mina<<endl;
		int ans=INT_MIN;
		for(int i=mina;i<=maxa;i++)//2*ai
		{
			memset(dif,0,sizeof(dif));
			for(int j=0;j<n;j++) dif[j]=abs(i-a[j]);
			//for(int j=0;j<n;j++) cout<<dif[j]<<' ';
			//cout<<endl;
			sort(dif,dif+n);
			int anss=n,summ=0;
			for(long long q=0;q<n;q++)//n
			{
				if(summ+dif[q]>m) 
				{
					anss=q;
					break;
				}
				summ+=dif[q];
			}
			ans=max(ans,anss);
			//cout<<anss<<endl;
		}
		cout<<ans<<endl;
		return 0;
	}
	else //luan gao maybe #13~15 or more
	{

		long long summ=0;
		for(long long i=1;i<=n;i++) cin>>a[i],summ+=a[i];
		double mi=(1.0*summ)/(1.0*n);
		long long mid=(long long)mi;
		for(long long i=1;i<=n;i++) dif[i]=abs(a[i]-mid);
		//for(long long i=0;i<n;i++) cout<<dif[i]<<' ';
		sort(dif+1,dif+n+1);
		long long ans=n,sum=0;
		for(long long i=1;i<=n;i++)
		{
			if(sum+dif[i]>m) 
			{
				ans=i-1;
				break;
			}
			sum+=dif[i];
		}
		//cout<<mi<<endl;
		/*cout<<endl;
		cout<<"mid "<<mid<<endl;
		cout<<"-----------------------------"<<endl;*/
		cout<<ans<<endl;
		return 0;
	}
}

