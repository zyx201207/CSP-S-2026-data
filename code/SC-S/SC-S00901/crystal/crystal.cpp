#include <bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<ll> q;
ll a[500005],b[500005],dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=m;
	}
	ll maxx=1e13;//最大可得到的水晶能量值
	for(ll i=1;i<=n;i++)maxx=min(maxx,a[i]);
	for(ll i=1;i<=n;i++)a[i]-=m;
	ll k=0;
	for(ll i=1;i<=n;i++)
		if(a[i]<=maxx)q.push(a[i]),b[++k]=a[i];
	maxx=q.top();
	ll sum=0,t=0,ans=0,s=0;
	for(ll i=1;i<=k;i++){
		sum+=maxx-b[i];
		if(sum<=m){
			t=i;//t是此时的最大个数 
			//cout<<"t: "<<t<<" sum: "<<sum<<"\n";
		}
		//如果5不行，就换成2 
		else{
			//if(b[i]==maxx)b[i]=0;
			s++;
			q.pop();
			maxx=q.top();
			//cout<<maxx<<" ";
			//cout<<"t: "<<i<<" sum: "<<sum<<"\n";
			sum=0;
			i=0;
		}
	}
	//cout<<s<<" ";
	cout<<t-s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 