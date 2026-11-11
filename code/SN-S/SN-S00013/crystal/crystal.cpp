#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll m;
int n,a[N];
int check(int x){
	int cnt=0,k=1;
	ll now=0;
	for(int i=x;i>=1;i--){
		ll t=a[x]-a[i];
		if(now+t<=m){
			now+=t;
			cnt++;
		}
		else return cnt;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxn=-1,tmp;
	for(int i=1;i<=n;i++){
		tmp=check(i);
		if(tmp>maxn) maxn=tmp;
	}
	cout<<maxn;
	return 0;
}
