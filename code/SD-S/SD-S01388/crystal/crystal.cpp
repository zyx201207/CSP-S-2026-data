#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=5e5+51;
ll n,m;
ll q[N];
ll cha[N];
ll maxn=0,jz;
ll l=0,r=1;
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+1+n,cmp);
	for(int i=2;i<=n;i++){
		cha[i]=q[i]-q[i-1];
	}
	jz=q[1];
	for(int i=2;i<=n;i++){
		ll val=cha[i]*(i-1);
		if(m>=val){
			m-=val;
			r++;
			jz=q[r];
		}
		else break;
	}
	maxn=max(maxn,r);
	for(int i=1;r<n;i++){
		m+=jz-q[++l];
		ll val=cha[r+1]*(r-l);
		while(r<n&&m>=val){
			r++;
			m-=val;
			jz=q[r];
			val=cha[r+1]*(r-l);
		}
		maxn=max(maxn,r-l);
	}
	cout<<maxn;
	return 0;
}


