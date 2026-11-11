#include <bits/stdc++.h>
using namespace std;
#define N 2000000
int c,t,n;
long long A[N+5],d,cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>A[i];
		for(int i=1;i<n;i++)cnt=max(A[i+1]-A[i],cnt);
		cnt=d/cnt;
		if(cnt>1&&cnt+cnt-1<=n)cout<<(n-cnt-cnt+1)<<'\n';
		else cout<<0<<"\n";
	}
	return 0;
}
