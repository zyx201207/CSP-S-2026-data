#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int z1=1,zn=n,n1=0,nn=a[zn];
	int ans=0;
	while(1){
		if(c[z1]!=c[zn]){
			if(a[z1]-n1 < nn){
				ans+=a[z1]-n1;
				nn-=(a[z1]-n1),z1++,n1=0;
			}
			else {
				ans+=nn;
				n1+=nn;
				if(n1==a[z1])z1++,n1=0;
				zn--;nn=a[zn];
			}
		}
		else {
			if(a[z1]-n1 < nn){
				nn-=(a[z1]-n1),z1++,n1=0;
			}
			else {
				n1+=nn;
				if(n1==a[z1])z1++,n1=0;
				zn--;nn=a[zn];
			}
		}
		if(z1>=zn)break;
//		cerr<<z1<<" "<<zn<<" "<<n1<<" "<<nn<<" "<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
/*
3
2 a
2 b
1 c
*/
