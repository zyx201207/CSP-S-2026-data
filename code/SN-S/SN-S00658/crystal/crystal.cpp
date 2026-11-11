//WA 60
#include<bits/stdc++.h>
#define ll long long
#define fri(x,y) for(ll i = x;i <= y;i++)
#define frj(x,y) for(ll j = x;j <= y;j++)
#define lihaoming 0
using namespace std;
ll a[500010];
ll n,m;
ll ans,cnt;
bool speacial_A = 1;
bool cmp(ll x,ll y){
	return x < y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	fri(1,n){
		cin>>a[i];
		if(a[i] != i){
			speacial_A = 0;
		}
	}
	sort(a + 1,a + n + 1,cmp);
	fri(1,n){
		cnt = 0;
		if(speacial_A){
			cnt = i * (i - 1) / 2;
		}
		else frj(1,i - 1){
			cnt += a[i] - a[j];
		}
		if(cnt <= m){
			ans = max(i,ans);
		}
	}
	cout<<ans;
	return lihaoming;
}
/*
O(n^2) 12*5 pts
#1~9 #13~15
*/
