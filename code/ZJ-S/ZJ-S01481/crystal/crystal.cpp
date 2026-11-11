#include <bits/stdc++.h>

using namespace std;

const int N=5e5+5;

int n,ans;

long long m,a[N],d[N];

long long sum[N];

bool flag,flag2;

/*
long long tr[N<<2];

int l[N<<2],r[N<<2];

void build(int id,int l1,int r1)
{
	l[id]=l1,r[id]=r1;
	if(l1==r1)
	{
		tr[id]=a[l1];
		return ;
	}
	int mid=(l1+r1)>>1;
	int ls=(id<<1),rs=((id<<1)|1);
	build(ls,l1,mid);
	build(rs,mid+1,r1);
	tr[id]=tr[ls]+tr[rs]+(l[rs]-l[ls])*(d[l[ls]]-d[l[rs]]);
}

int query(int id,int fl,int fr)
{
	if(fl<=l[id]&&r[id]<=fr)
	{
		return tr[id];
	}
	int mid=(l[id]+r[id])>>1;
	int ls=(id<<1),rs=((id<<1)|1);
	long long res=0;
	if(fl<=mid) res+=query(ls,fl,mid);
	if(fr>mid) res+=query(rs,mid,fr);
	if(fl<=mid&&fr>mid) res+=(mid-fl)*(d[fl]-d[mid]);
//	cout<<"q"<<l[id]<<' '<<r[id]<<' '<<mid<<' '<<fl<<' '<<d[fl]<<' '<<d[mid]<<' '<<res<<endl;
	return res;
}
*/

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=a[1]) flag=1;
		if(i>1&&a[i]-a[i-1]!=a[2]-a[1]) flag2=1;
	}
	if(!flag)
	{
		cout<<n<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	if(!flag2)
	{
		for(int i=n-1;i>=1;i--)
		{
			if(i+1<=ans) break;
			sum[i+1]=0;
			int L=1,R=i,tot=i;
			while(L<R)
			{
				int mid=(L+R)>>1;
				if(a[1]*(i-mid-1)*(i-mid)/2<=m)
				{
					R=mid-1;
					tot=min(tot,mid);
				}
				else L=mid+1;
			}
			if(sum[L]) tot=L;
			ans=max(ans,i-tot+2);
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<n;i++) a[i]=a[i+1]-a[i];
	for(int i=n-1;i>=0;i--) d[i]=d[i+1]+a[i];
//	build(1,1,n-1);
//	cout<<query(1,1,3)<<endl;//<<' '<<query(1,2,3)<<endl;
	/*
	for(int i=n-1;i>=1;i--)
	{
		if(i+1<=ans) break;
		int L=1,R=i,tot=i;
		while(L<R)
		{
			int mid=(L+R)>>1;
			if(query(1,mid,i)<=m)
			{
				R=mid-1;
				tot=min(tot,mid);
			}
			else L=mid+1;
		}
		if(query(1,L,i)<=m) tot=L;
		ans=max(ans,i-tot+2);
	}
	*/
	for(int i=n-1;i>=1;i--)
	{
		if(i+1<=ans) break;
		sum[i+1]=0;
		for(int j=i;j>=1;j--)
		{
			sum[j]=sum[j+1]+a[j]*(i-j+1);
		}
		int L=1,R=i,tot=i;
		while(L<R)
		{
			int mid=(L+R)>>1;
			if(sum[mid]<=m)
			{
				R=mid-1;
				tot=min(tot,mid);
			}
			else L=mid+1;
		}
		if(sum[L]) tot=L;
		ans=max(ans,i-tot+2);
	}
	cout<<ans<<endl;
	return 0;
}
