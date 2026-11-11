#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],ans=1,b[N];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i-1]-a[i];
	}
	ll i=1,j=2,cnt=0;
	while(j<=n&&i<=n)
	{
		cnt+=b[j];
		if(m>=cnt)
		{
			m-=cnt;
			if(j==n){
				ans=max(ans,j-i+1);
				break;
			}
			j++;
		}else{
			ans=max(ans,j-i);
			i++;
			cnt-=b[i];
			m+=b[i]*(j-i);
		}
	}
	cout<<ans;
	return 0;
}

