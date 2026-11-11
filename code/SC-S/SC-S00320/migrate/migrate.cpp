#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+7;
int c,t,n;
ll d,x[MAXN];

void work1(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;++i) cin>>x[i];
	for(int i=1;i<=n-3;++i){
		if(x[i+2]-x[i]<=d&&x[i+3]-x[i]>d&&x[i+3]-x[i+2]<=d){
			ans++;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) work1();
	return 0;
}
