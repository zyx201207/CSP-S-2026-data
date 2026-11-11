#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],m,x,ans,sum;
queue<long long>q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*x,q.push(a[i]),x++;
		while(sum>m&&!q.empty())
			sum-=(a[i]-q.front()),q.pop(),x--;
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}