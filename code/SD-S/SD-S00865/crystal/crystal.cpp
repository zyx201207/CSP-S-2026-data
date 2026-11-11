#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;long long m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long cnt=0;
	for(long long i=2;i<=n;i++){
		cnt+=(i-1LL)*(a[i]-a[i-1]);
		if(cnt>m){
			cout<<i-1;
			return 0;
		}
	}cout<<n;
	return 0;
}
