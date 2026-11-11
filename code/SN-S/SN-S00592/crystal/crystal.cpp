#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+114;
int n;
ll m;
ll a[N];
ll s[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int p=0;
		for(int j=1<<30;j;j>>=1){
			if(p+j<=i&&((i-(p+j)+1)*a[i]-s[i]+s[p+j-1]>m))p+=j;
		}
		p=min(p+1,i);
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
//WSY
//non terrae plus ultra
