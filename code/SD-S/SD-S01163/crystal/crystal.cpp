#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005],mm;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int b=0;
	mm=m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=n-1;
	int nn=1;
	for(int i=n;i>1;i--){
		j=min(j,i-1);
		for(;j>=1;j--){
				//cout<<j<<" "<<a[i]-a[j]<<endl;
			if(mm>=(a[i]-a[j])){
				mm-=(a[i]-a[j]);
				nn++;
			}else{
				ans=max(ans,nn);
				mm=mm+(a[i]-a[i-1])*(nn-1);
				nn-=1;
				if(nn==0){
					nn=1;
				}
				break;
			}
		}
	}
	ans=max(ans,nn);
	cout<<ans;
	return 0;
}
