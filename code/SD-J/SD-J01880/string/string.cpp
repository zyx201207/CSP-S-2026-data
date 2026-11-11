#include<bits/stdc++.h>
using namespace std;
#define int long long  
#define N 200010
void Freopen()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return ;
}
int n,ans;
struct Node{
	int x;
	char t;
}A[N];
signed main()
{
	Freopen();
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{ 
		scanf("%lld %c",&A[i].x,&A[i].t);
	}
	int j=n;
	for(int i=1;i<=n&&i<j;)
	{
		if(A[i].t!=A[j].t)
		{
			if(A[i].x==A[j].x)
			{
				ans+=A[i].x;
				i++,j--;
			}else if(A[i].x<A[j].x){
				ans+=A[i].x;
				A[j].x-=A[i].x;
				i++;
			}else{
				ans+=A[j].x;
				A[i].x-=A[j].x;
				j--;
			}
		}else{
			if(A[i].x==A[j].x)
			{
				i++,j--;
			}else if(A[i].x<A[j].x){
				A[j].x-=A[i].x;
				i++;
			}else{
				A[i].x-=A[j].x;
				j--;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

