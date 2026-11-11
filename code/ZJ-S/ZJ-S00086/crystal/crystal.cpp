#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+100;
typedef long long ll;

ll n,m,a[MAXN],ans=1;

queue<ll> q;

bool cmp(ll a,ll b){
	return a<b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	q.push(a[1]);
	ll k=2,cnt=0;
	while(!q.empty()&&k<=n){
		ll len=q.size();
		cnt+=len*(a[k]-q.back());
		q.push(a[k]);
		while(cnt>m){
			cnt-=q.back()-q.front();
			q.pop();
		}
		k++;
		ll anss=q.size();
		ans=max(anss,ans);
	}
	cout<<ans;
	return 0;
}
