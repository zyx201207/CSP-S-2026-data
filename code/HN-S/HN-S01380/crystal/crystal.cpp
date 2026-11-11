#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
struct ovo{
	int shu,sum;
}b[N];
int n,m,a[N],c[N],q[N],l=1,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	//freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+(a[i]-a[i-1])*(i-1);
		int S=c[i]-c[l]-(l-1)*(a[i]-a[l]);
		while(S>m){
			l++;
			S=c[i]-c[l]-(l-1)*(a[i]-a[l]);
		}
		ans=max(ans,(i-l+1));
	}
	cout<<ans;
	return 0;
} 
