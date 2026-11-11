#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int n,d;
long long a[N];
long long v[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v[i]=1;
	}
	long long ans=0;
	int t=1;
	for(int h=2;h<=n;h++){
		int tmp=t;
		while(a[h]-a[t]>d)t++;
		if(h-t==2){
			ans+=t-tmp;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}