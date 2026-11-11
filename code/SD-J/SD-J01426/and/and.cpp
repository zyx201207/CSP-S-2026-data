#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[300010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int p=0;
	int ta=0;
	int tb=0;
	int z=1;
	while(z<n) z*=2;
	if(z==n) tb++;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i-1) tb++;
		if(a[i]<4){
			p++;
		}
		int y=a[i];
		y++;
		int f=1;
		while(f<y){
			f*=2;
		}
		if(f==y){
			ta++; 
		}
	}
	sort(a+1,a+n+1,greater<int>());
	if(ta==n||tb==n+1||p==n){
		cout<<a[m];
	}else if(m==n){
		int maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
	}else if(m==1){
		int maxn=-2e9;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn; 
	}else if(m==2){
		int maxn=-2e9; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
	}else{
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
