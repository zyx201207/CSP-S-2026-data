#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MXN = 2e6+10;
int n,L[MXN],R[MXN],Le[MXN],Re[MXN],Rinto[MXN];
ll m,f[MXN],a[MXN],ans;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;cin>>C>>T;
	while(T--)
	{
		cin>>n>>m;
//		cout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int l=1,r=1;l<=n;l++)
		{
			while(r<n&&a[r+1]-a[l]<=m) r++;
			R[l]=r;
//			cout<<R[l]<<" ";
		}
		for(int r=n,l=n;r>=1;r--)
		{
			while(l>1&&a[r]-a[l-1]<=m) l--;
			L[r]=l;Rinto[l]++;
		}
//		cout<<endl;for(int i=1;i<=n;i++) cout<<L[i]<<" ";	cout<<endl;
		for(int i=1;i<n;i++) if(L[R[i]]==i) Le[R[i]]=Le[i]+1;
		for(int i=n;i>1;i--) if(R[L[i]]==i) Re[L[i]]=Re[i]+1;
		for(int i=1;i<n;i++)
		{
//			cout<<f[i]<<" ";
			if(i>1&&R[i]>i+1&&L[R[i]-1]==i-1&&L[R[i]]>i-1&&R[i-1]<R[i])//keep edge
			{
//				cout<<"Keep ";
				f[R[i]]+=f[i];
			}
			if(R[i]>i+1&&L[R[i]-1]==i)//flat start
			{
//				cout<<"FlatStart ";
				f[R[i]]+=Le[i]+1;
			}
			if(R[i]>i+1&&L[R[i]-1]<i)//start
			{
//				cout<<"Start ";
				f[R[i]]+=1;
			}
			if(L[R[i]]==i-1)//flat end
			{
//				cout<<"FlatEnd ";
				ans+=f[i]*(Re[R[i]]+1);
			}
			if(i>1&&R[i]>i+1&&L[i]<i-1&&R[i-1]>i)//end
			{
//				cout<<"End "<<(Rinto[i-1]-(L[R[i]]==i-1))<<" ";
				ans+=f[i]*(Rinto[i-1]-(L[R[i]]==i-1));
			}
//			cout<<ans<<endl;
		}
		cout<<ans<<endl;
//		cout<<endl;
//		recover
		for(int i=0;i<=n+5;i++)
		{
			a[i]=f[i]=L[i]=R[i]=Le[i]=Re[i]=Rinto[i]=0;
		}ans=0;
	}
	return 0;
}
