#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m;
ll a[N],ans;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	int p=n;
	bool flag=true;
	while(p!=0){
		if(p%2==0){
			flag=false;
			break;
		}
		p/=2;
	}
	if(m==1){
		cout << 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll x=(a[i]&a[j]);
				ans=max(ans,x);
			}
		}
		cout << ans;
	}
	else if(flag){
		cout << 0;
	}
	else{
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=(ans&a[i]);
		}
		cout << ans;
	}
	return 0;
}