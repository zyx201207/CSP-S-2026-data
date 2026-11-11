#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
long long hzt,l,r,dl,dr;
int ans=1;
int midl,midr;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n%2==0){
		hzt=a[n/2];
		midl=1;
	}
	else{
		hzt=a[n/2+1];
		midr=1;
	}
	while(m and (n/2-midl>=1 or n/2+1+midr<=n)){
		l=a[n/2-midl];
		r=a[n/2+1+midr];
		dl=hzt-l;
		dr=(r-hzt)*ans;
		if(n/2-midl>=1 and n/2+1+midr<=n){
			if(dl<dr){
				if(dl<=m){
					m-=dl;
					ans++;
					a[n/2-midl]=hzt;
					midl++;
				}else break;
			}else{
				if(dr<=m){
					m-=dr;
					ans++;
					hzt=a[n/2+1+midr];
					midr++;
				}else break;
			}
		}else{
			if(n/2-midl>=1){
				if(dl<=m){
					m-=dl;
					ans++;
					a[n/2-midl]=hzt;
					midl++;
				}else break;
			}
			if(n/2+1+midr<=n){
				if(dr<=m){
					m-=dr;
					ans++;
					hzt=a[n/2+1+midr];
					midr++;
				}else break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
