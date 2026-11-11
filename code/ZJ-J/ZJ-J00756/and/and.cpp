#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
int a[N],f[N],s1,c[N],maxn,xx;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[0]=4294967295;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=0;j--){
			f[j+1]=max(f[j+1],a[i]&f[j]);
		}
	}
	cout<<f[m];
	return 0;
}
