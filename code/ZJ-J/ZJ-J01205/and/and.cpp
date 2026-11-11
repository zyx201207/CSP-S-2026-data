#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
	ll v,pos;
};

ll n,m;
ll a[200010];
bool wei[200010][35];
node can[200010];
ll ans;

bool cmp(node x,node y){
	return x.v<y.v;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ll a1=a[i],pos=1;
		while(a1!=0){
			wei[i][pos]=a1%2;
			a1/=2;
			pos++;
		}
	}
	for(ll i=1;i<=n;i++){
		can[i].pos=i;
	}
	for(ll w=34;w>=0;w--){
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			if(wei[i][w]==1){
				cnt++;
			}
		}
		if(cnt>=m){
			ans=-1;
			for(ll i=1;i<=n;i++){
				if(wei[i][w]==1){
					can[i]={can[i].v+(1<<w),can[i].pos};
				}
			}
		}
	}
	sort(can+1,can+n+1,cmp);
	ans=-1;
	ll times=m;
	for(ll i=n;i>=1;i--){
		if(!times)break;
		if(ans==-1){
			ans=a[can[i].pos];
		}
		else ans&=a[can[i].pos];
		times--;
	}
	cout<<ans;
	return 0;
}
