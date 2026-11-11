#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef pair<int,int>pii;
//typedef pair<ll,ll> pll;
const int MAXN=5e5+5;
int n,m;
ll a[MAXN];
ll pre[MAXN];
int ans=0;
ll f(ll x,ll y){
	return pre[y]-(a[y]-a[x])*x-pre[x];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	pre[1]=0;
	int id=0;
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+ll(a[i]-a[i-1])*(i-1);
		if(pre[i]<=m){
			id=i;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<pre[i]<<" ";
//	}
	int head=1,tail=id+1;
	ans=id;
	for(int i=id+1;i<=n;i++){
		while(head<=tail && f(head,i)>m){
			head++;
		}
		while(head<=tail && f(head,i)<=m){
			i++;
			if(i>=n){
				break;
			}
		}
		tail=i;
		if(f(head,tail)>m) tail--;
		ans=max(ans,tail-head);
	}
	cout<<ans;
	return 0;
}

