#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,aa,a[200005][32],v[200005],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa;
		int l=0;
		while(aa){
			a[i][++l]=aa%2;
			aa/=2;
		}
	}
	for(int l=31;l>=1;l--){
		int s=0;
		for(int i=1;i<=n;i++){
			if(!v[i]&&a[i][l]){
				s++;
			}
		}
		if(s>=m){
			ans+=(int)pow(2,l-1);
			for(int i=1;i<=n;i++){
				if(!a[i][l]){
					v[i]=1;
				}
			}
		}
	}
	cout<<ans;
}
