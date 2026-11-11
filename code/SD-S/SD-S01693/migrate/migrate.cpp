#include<bits/stdc++.h>
using namespace std;
long long cc,tt,n,d,cnt,maxx=LLONG_MIN;
long long a[2000006],sum[2000006],fsum[2000006];
long long fly[2000006],ffly[2000006];
bool fhpd;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>tt;
	while(tt--)
	{
		cin>>n>>d;
		cnt=0;
		maxx=LLONG_MIN;
		for(int i=1;i<=n;i++)
		{
			
			cin>>a[i];
//			pd[a[i]]=true;
			if(a[i]+1<0)
			{
//				cout<<-(a[i]+1)<<' ';
				fhpd=true;
				ffly[-(a[i]+1)]++;
				maxx=max(maxx,-(a[i]+1));
			}
			else if(a[i]+1<=n) fly[a[i]+1]++;
			else fly[n]++;
			if(a[i]+d+1<0)
			{
				fhpd=true;
				ffly[-(a[i]+d+1)]--;
				maxx=max(maxx,-(a[i]+1+d));
			}
			else if(a[i]+d+1<=n) fly[a[i]+d+1]--;
			else fly[n]--;
		}
		for(int i=maxx;i>=1;i--)
		{
			fsum[i]=fsum[i+1]+ffly[i];
			ffly[i]=0;
//			cout<<fsum[i]<<' ';//
			if(fsum[i]==2) cnt++;
		}
		sum[0]=fsum[1]+fly[0];
//		cout<<sum[0]<<' ';//
		if(sum[0]==2) cnt++;
		fly[0]=0;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+fly[i];
			fly[i]=0;
//			cout<<sum[i]<<' ';//
			if(sum[i]==2) cnt++;
		}
//		cout<<endl;//
		if(fhpd) cnt-=2;
		cout/*<<endl*/<<cnt<<endl;
	}
	return 0;
}
