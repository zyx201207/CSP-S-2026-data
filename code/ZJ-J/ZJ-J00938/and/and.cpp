#include<bits/stdc++.h>
using namespace std;
const long long int mi[34]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592};
long long int n,m,sum,t=-1;
struct node
{
	long long int x,y,z;
};
node a[200020];
vector<int> T[35];
void ef(int x,int t)
{
	int l=1,r=31,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(mi[mid-1]<=x&&mi[mid]>=x)
		{
			if((mi[mid]-x)==0)
			{
				a[t].y=mi[mid];
				a[t].z=mid;
				T[mid].push_back(a[t].x);
			}
			else
			{
				a[t].y=(mi[mid]-x);
				a[t].z=mid-1;
				T[mid-1].push_back(a[t].x);
			}
			return ;
		}
		if(mi[mid]<x) l=mid+1;
		else r=mid-1;
	}
	a[t].y=mi[l]-x;
	a[t].z=l-1;
	T[l-1].push_back(a[t].x);
}
bool cmp(node aa,node bb)
{
	if(aa.z!=bb.z) return aa.z>bb.z;
	if(aa.y!=bb.y) return aa.y<bb.y;
	else return aa.x>bb.x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
//		cin>>a[i].x;
		ef(a[i].x,i);
	}
	if(n==m)
	{
		sum=a[n].x;
		for(int i=1;i<n;i++)
		{
			sum=sum&a[i].x;
		}
		cout<<sum<<endl;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
//	}
	for(int i=34;i>=1;i--)
	{
//		cout<<i<<" "<<(T[i].size())<<endl;
		if(T[i].size()>=m&&t==-1)
		{
			t=i;
			break;
		}
	}
//	cout<<t<<endl;
	if(t==-1)
	{
		sum=a[m].x;
		for(int i=1;i<m;i++)
		{
//			cout<<sum<<" "<<a[i].x<<endl;
			sum=sum&a[i].x;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i].z==t)
			{
				sum=a[i].x;
				for(int j=2;j<=m;j++)
				{
//					cout<<sum<<" "<<a[i+j-1].x<<endl;
					sum=sum&a[(i+j-1)].x;
				}
				break;
			}
		}
	}
	cout<<sum<<endl;
}