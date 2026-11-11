#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,sum1,res,cl;
struct Node{
	long long sum,cnt=0;
}a[200010];
bool cmp(Node x,Node y)
{   if(x.cnt!=y.cnt)return x.cnt>y.cnt;
	return x.sum>y.sum;
}
int main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	cin>>n>>m;
	sum1=n-m;
	for(int i=1;i<=n;i++)
	{   cin>>a[i].sum;
		cl=a[i].sum;
		while(cl){
			if(cl%2==1)a[i].cnt++;
			cl/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].sum;
	for(int i=2;i<=m;i++)
	{	long long h=ans&a[i].sum;
		if((h==0)&&res<sum1)m++,res++;
		else ans=ans&a[i].sum;
	}
	cout<<ans;
	return 0;
}

