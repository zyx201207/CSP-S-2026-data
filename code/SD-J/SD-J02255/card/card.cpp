#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n];
	long long i,j;
	for(i=0;i<n;i++)cin>>a[i];
	int ans[m+1];
	for(i=1;i<=n;i++){
		int q[n-i],y=0;
		for(j=i-1;j<n;j++){
		int x=-1;
		for(long long g=0;g<n-1;g++){
			if(a[i]==x)x=g;
		}
			if(x>=0){
				for(int d=x;d<=y;d++)q[d]=0;
				for(int d=0;q[d]!=0;d++)y=d+1;
			}
			q[y]=a[j];
		}
		for(j=0;j<y;j++){
			ans[q[j]]++;
		}
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
