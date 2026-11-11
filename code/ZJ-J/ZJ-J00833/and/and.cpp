#include<bits/stdc++.h>
using namespace std;
int n,m,c=1;
long long a[200005],ans,ma;
bool cmp(long long x,long long y){
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//ma=max(ma,a[i]);
	}
	//ma=int(log2(ma));
	sort(a+1,a+n+1,cmp);
	while(int(log2(a[c]))>int(log2(a[c+m-1]))&&c<n){
		c++;
	}
	
	//cout<<c<<' ';
	ans=a[c];
	for(int i=c+1;i<=c+m-1&&i<=n;i++){
		ans&=a[i];
		//cout<<a[i]<<' ';
	}
	cout<<ans;
}
	
	
	