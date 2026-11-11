#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,sum,s[N];
bool flag=0;
void work(){
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			s[i]+=(a[i]-a[j]);
		}
	}	
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			flag=1;
		}
	}
	if(!flag){
		if(m/2+1<=n){
			cout<<m/2+1;
		}
		else cout<<n;
		return 0;
	}
	flag=0;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]+a[i-2]){
			flag=1;
		}
	}
	if(!flag){
		int x=m/(a[n]-a[n-1]);
		cout<<x;
		return 0;
	}
	work();
	for(int i=n;i>=1;i--){
		if(s[n-i]==m)ans=n-i;
	}
	cout<<ans;
	return 0;
}
