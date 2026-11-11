#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll a[200010],a2[200010];
char c[200010],c2[200010];
ll sum[200010],sum2[200010];

struct node{
	ll pos;
	ll apos,bpos;
};
node t[400010];
bool cmp(node x,node y){
	return x.pos<y.pos;
}

ll ans,mid,res,num,l,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		a2[i]=a[n-i+1];
		c2[i]=c[n-i+1];
		sum2[i]=sum2[i-1]+a2[i];
	}
	l=r=1;
	num=1;
	for(l=1;l<=n;l++){
		t[num]={sum[l],l,lower_bound(sum2+1,sum2+n+1,sum[l])-sum2};
		num++;
	}
	for(r=1;r<=n;r++){
		t[num]={sum2[r],lower_bound(sum+1,sum+n+1,sum2[r])-sum,r};
		num++;
	}
	sort(t+1,t+num,cmp);
	for(ll i=1;i<=num-1;i++){
		node now=t[i];
		ll pos=now.pos;
		ll lastpos=t[i-1].pos;
		ll lpos=now.apos;
		ll rpos=now.bpos;
		if(c[lpos]!=c2[rpos]){
			ans+=pos-lastpos;
		}
	}
	cout<<ans/2;
	return 0;
}
