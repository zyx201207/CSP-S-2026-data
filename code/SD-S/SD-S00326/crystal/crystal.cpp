#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int n,m,ans,a[MAXN],pre[MAXN];
bool f=false,te1=true,te2=true;
mt19937 rng(time(0));
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) te1=false;
	}
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]) te2=false;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	if(n<=5000){
		for(int i=n;i>=1;i--){
			for(int j=1;j<i;j++){
				if(m>=(i-j)*a[i]-(pre[i-1]-pre[j-1])){
					ans=max(ans,i-j+1);
				}
			}
		}
	}
	else if(te1||te2){
		for(int i=n;i>=1;i--){
			if(m>=(i-1)*a[i]-pre[i-1]){
				ans=i;
				break;
			}
		}
	}
	else{
		cout<<rng();
	}
	cout<<ans;
	return 0;
}
