#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],pll,ans;
bool FC=1,FAB=1;
signed main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(abs(a[i])>100) FC=0;
		if(i>=3 && a[i]-a[i-1]!=a[2]-a[1]) FAB=0;
	}
	sort(a+1,a+n+1);
	
	if(FC) {
		for(pll=-100;pll<=100;pll++) {
			int f=lower_bound(a+1,a+n+1,pll)-a;
			if(f==n+1) {
				int sum=0,ns=0;
				for(int j=n;j>=1;j--){
					if(sum+pll-a[j]<=m) {
						sum+=pll-a[j];
						ns++;
					}
					else break;
				}
				ans=max(ans,ns);
				break;
			}
			else{
				int sum=0,ns=0;
				if(pll!=a[f]) f--;
				else while(a[f]==a[f+1]) f++;
				for(int j=f;j>=1;j--){
					if(sum+pll-a[j]<=m){
						sum+=pll-a[j];
						ns++;
					}
					else break;
				}
				ans=max(ans,ns);
			}
		}
		cout<<ans;
		return 0;
	}
	if(FAB){
		int sum=0,ns=0;
		pll=a[n];
		for(int j=n;j>=1;j--){
			if(sum+pll-a[j]<=m){
				sum+=pll-a[j];
				ns++;
			}
			else break;
		}
		ans=ns;
		cout<<ans;
		return 0;
	}
	for(int i=n;i>=1;i--){
		int sum=0,ns=0;
		pll=a[i];
		for(int j=i;j>=1;j--){
			if(sum+pll-a[j]<=m){
				sum+=pll-a[j];
				ns++;
			}
			else break;
		}
		ans=max(ans,ns);
	}
	cout<<ans;
	return 0;
}//90