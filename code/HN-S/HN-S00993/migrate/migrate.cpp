#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2000005],sum[2000005],k,b[2000005],f[2000005][23],lg[2000005],rsum[2000005],rb[2000005],book[2000005];
int findmax(int x,int y)
{
	if(x>y)
		swap(x,y);
	int lgg=lg[y-x+1];
	return max(f[x][lgg],f[y-(1<<lgg)+1][lgg]);
}
main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	cerr<<sizeof(f)/1024/1024+sizeof(a)/1024/1024*4;//410mb
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout<<LONG_LONG_MAX;
	int c,t;
	cin>>c>>t;
	for(int i=2;i<=2000000;++i)
		lg[i]=lg[i/2]+1;
	while(t--)
	{
		int ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;++i)
		{
			book[i]=rsum[i]=rb[i]=a[i]=b[i]=sum[i]=0;
			for(int j=0;j<=22;++j)
				f[i][j]=0;
		}
		for(int i=1;i<=n;++i)
			cin>>a[i];
		//先敲暴力
		for(int i=1;i<=n;++i)
		{
			b[i]=upper_bound(a+1,a+1+n,a[i]+k)-a-1;
			if(b[i]>n)
				b[i]=n;
			sum[i]++;
			rsum[i]++;
			f[i][0]=b[i];
			rb[b[i]]=i;
			book[b[i]]++;
		//	cout<<rb[i];
		}
		/*
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
			{
				if(b[i])
			}
		*/
		for(int i=1;i<=n;++i)//求st表,与B有关
			for(int j=1;j<=22;++j)
				if(i+(1<<j)<=n)
					f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		//cout<<"\n"<<findmax(1,2)<<"\n";
		for(int i=1;i<=n;++i)
		{
			if(b[i]==b[n])
				break;
			int y=b[i];
			sum[y]+=sum[i];
			if(b[y-2]==b[y-1])//他不是新代理
				continue;
			if(b[y-1]<=y)//本是同根生
				continue;
		}
		for(int i=n;i>=1;--i)
		{
			if(b[i]==b[1])
				break;
		//	cout<<rb[i]<<" "<<i<<"\n";
			rsum[rb[i]]+=rsum[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(b[i]==b[i-1])
				continue;
			if(b[i]==b[n])
				break;
			int y=b[i];
			if(b[y-2]==b[y-1])//他不是新代理
				continue;
			if(b[y-1]<=y)//本是同根生
				continue;
			//cout<<rsum[b[b[y-1]]]<<"\n";
			ans+=(sum[i]+book[b[i]]-1)*(b[y-1]-findmax(i,y-2)+rsum[b[y-1]]);
		}
		cout<<ans<<"\n";
		//直接刻画
	}
}
/*
17:02
2 3 4 6 7 7 8 9 10 10
 
 
 

16：00
9 7
1 2 3 7 8 11 12 13 14
16：29
考虑直接一个st表，然后就做完了，简单计算即可
16: 55
* 调试
*/
//没崩


//有点困/jk，不管了不管了，最后一搏
