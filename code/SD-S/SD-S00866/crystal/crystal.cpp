#include <bits/stdc++.h>
using namespace std;
const int M=5e5;
long long n,m,a[M+5];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long r=1,ned=m,fc=a[1],ans=0;
	for (int l=1;l<=n;l++){
		while (r<n){
			r++;
			ned-=(a[r]-fc)*(r-l);
			if (ned<0){
				ned+=(a[r]-fc)*(r-l);
				r--;
				
				break;
			}
			fc=a[r];
		}
		ans=max(ans,r-l+1);
		ned+=(fc-a[l]);
	}
	cout<<ans<<endl;
	return 0;
}

