#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],lp,rp,l,r,ans,sum;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	r=n+1;
	while(lp<=sum/2&&rp<=sum/2||lp<sum/2&&rp>sum/2||lp>sum/2&&rp<sum/2){
		if(lp<rp){
			l++;
			lp+=a[l];
			if(lp<rp){
				if(c[l]!=c[r])ans+=a[l];
			}else{
				if(c[l]!=c[r])ans+=rp-lp+a[l];
			}
		}else{
			r--;
			rp+=a[r];
			if(rp<lp){
				if(c[l]!=c[r])ans+=a[r];
			}else{
				if(c[l]!=c[r])ans+=lp-rp+a[r];
			}
		}
	}
	cout<<ans;
	return 0;
}
