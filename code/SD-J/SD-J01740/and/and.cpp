#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long a,sum=0;
}num[200005];
bool cmp(Node x,Node y)
{
	if(x.sum==y.sum)
		return x.a>y.a;
	return x.sum>y.sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i].a;
		long long x=num[i].a;
		while(x>0)
		{
			if(x%2==1)
				num[i].sum+=1;
			x/=2;
		}
	}
	sort(num+1,num+n+1,cmp);
	long long ans=num[1].a;
	for(int i=1;i<=m;i++)
		ans=ans&num[i].a;
	cout<<ans;
	return 0;
}
