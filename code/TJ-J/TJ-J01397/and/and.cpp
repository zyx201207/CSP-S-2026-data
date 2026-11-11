#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[100005];
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	int ans=-1;
	int j=0;
for(int i=1;i<=n;i++){
sum=a[i];
	 j=i+1;
int x=0;
	
	
	while(j<=n&&x<m){
		sum=sum&a[j];
	
		j++;
		x++;
		
	}
	ans=max(ans,sum);
}
cout<<ans;
	return 0;
}
