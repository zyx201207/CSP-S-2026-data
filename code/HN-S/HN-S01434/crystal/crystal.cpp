#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],g[N],dp[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1;
	for(int i=2;i<=n;i++){
		if(m-(a[i]-a[1])<0){
			break;
		}
		else{
			r++;
			m-=a[i]-a[1];
		}
	}
	dp[1]=r-l+1;
	for(int i=2;i<=n;i++){
		int p=a[i]-a[i-1];
		if(r>=i){
			m+=p*(r-i+1)-p*(i-l);
		}
		else{
			m-=p*(i-l);
			r++;
		}
		if(m<0){
			while(m<0){
				l++;
				m+=a[i]-a[l-1];
			}
		}
		while(m-(a[r+1]-a[i])+(a[i]-a[l])>=0 && r+1<=n){
			if(m-(a[r+1]-a[i])>=0){
				m-=(a[r+1]-a[i]);
				r++;
			}
			else{
				m=m-(a[r+1]-a[i])+(a[i]-a[l]);
				r++;
				l++;
			}
		}
		dp[i]=r-l+1;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
    return 0;
}


