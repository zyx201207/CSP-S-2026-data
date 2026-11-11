#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],S[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(x*a[i]-S[i]+S[i-x]<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) S[i]=S[i-1]+a[i];
	int L=1,R=n+1;
	while(L<R-1){
		int mid=(L+R)/2;
		if(check(mid)) L=mid;
		else R=mid;
	}
	cout<<L;
	return 0;
}
