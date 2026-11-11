#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500009;
const int N1_2=19;
const int N3_9=5009;
int n;
ll m;
ll a[N];
ll ans1_2=0;
void dfs1_2(int i,ll k){
	if(i>=n||k==0){
		ll cnt=0;
		int b[N1_2];
		for(int j=1;j<=n;j++)b[j]=a[j];
		sort(b+1,b+1+n);
		for(int j=1;j<=n;j++){
			if(b[j]!=b[j-1]){
			 	ans1_2=max(ans1_2,cnt);
			 	cnt=0;
			}
			cnt++;
		}
		ans1_2=max(ans1_2,cnt);
		return;
	}
	for(int j=0;j<=k;j++){
		a[i]+=j;
		dfs1_2(i+1,k-j);
		a[i]-=j;
	}
}
void solve1_2(){
	sort(a+1,a+1+n);
	dfs1_2(1,m);
	cout<<ans1_2;
}
ll ansA=1;
void solveA(){
	for(int i=1;i<=n;i++){
		if(m>=i*(i+1)/2)ansA=i+1;
	}
	cout<<ansA;
}
ll ansB=1;
void solveB(){
	m/=(a[2]-a[1]);
	for(int i=1;i<=n;i++){
		if(m>=i*(i+1)/2)ansB=i+1;
	}
	cout<<ansB;
}
bool cmp3_9(ll x,ll y){
	return x>y;
}
ll ans3_9=0;
void solve3_9(){
	sort(a+1,a+1+n,cmp3_9);
	for(int i=1;i<=n;i++){
		ll cnt=1;
		ll k=m;
		for(int j=i+1;j<=n;j++){
			k-=a[i]-a[j];
			if(k>=0)cnt++;
			else break;
		}
		ans3_9=max(ans3_9,cnt);
	}
	cout<<ans3_9;
}
bool cmp(ll x,ll y){
	return x>y;
}
ll ans=1;
void solve(){
	sort(a+1,a+1+n,cmp);
	ll k=0;
	ll l=1,r,len;
	for(int i=2;i<=n;i++){
		k+=a[1]-a[i];
		r=i-1;
		if(k>m){
			k-=a[1]-a[i];
			break;
		}
	}
	len=r-l+1;
	while(r<=n){
		if(k<=m){
			ans=max(ans,len);
			r++;
			len++;
			k+=a[l]-a[r];
		}
		if(k>m){
			k-=(len-1)*(a[l]-a[l+1]);
			l++;
			len--;
		}
	}
	cout<<max(ans,len);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool isA=1;
	bool isB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)isA=0;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])isB=0;
	}
	if(n<=5&&m<=10)solve1_2();
	else if(isA)solveA();
	else if(isB)solveB();
	else if(n<=5000&&m<=1e9)solve3_9();
	else solve();
	return 0;
}
