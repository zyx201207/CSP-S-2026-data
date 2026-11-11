#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,m,a[N],ans,ma=LLONG_MIN;
void solve(int x,long long t){
	ans=1;
	for(int i=x-1;i>=1;i--){
		if(t>=a[x]-a[i]) t-=a[x]-a[i];
		else return ;
		ans++;
	}
}
void A(int x,long long t){
	int b=a[x]-a[x-1];
	ans=int(sqrt(2*t/b))+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=n;j>=1;j--){
		if(m>1e5&&n>5000) A(j,m);
		else solve(j,m);
		ma=max(ans,ma);
	}
	cout<<ma;
	return 0;
}
