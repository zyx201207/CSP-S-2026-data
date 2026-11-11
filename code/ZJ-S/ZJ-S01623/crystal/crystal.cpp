#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1e2;
int n,m,ans;
int a[N],s[N],p[205];
int cost,maxx;
int flag;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) s[i]=a[i+1]-a[i];
	sort(s+1,s+n);
	if(n<=5000){
		for(int i=n;i>=1;i--){
			ans=0;
			for(int j=i;j>=1;j--){
				ans+=a[i]-a[j];
				if(ans>m) break;
				maxx=max(maxx,i-j+1);
			}
//			cout<<maxx<<"\n";
		}
		cout<<maxx;
	}
	if(n>5000){
		if(m<=1e8&&a[n]-a[1]<=200){
			for(int i=1;i<=n;i++) p[a[i]+100]++;
			for(int i=0;i<=200;i++){
				ans=0,cost=0;
				for(int j=i;j>=0;j--){
					if((i-j)*p[j]+cost<=m) ans+=p[j],cost+=(i-j)*p[j];
					else{
						ans+=(m-cost)/((i-j));
						cost+=(m-cost)/((i-j))*(i-j);
					}
				}
				maxx=max(maxx,ans);
			}
			cout<<maxx;
		}
		else if(s[1]==s[n-1]){
			int d=s[1];
//			n*(n+1)*d/2<=m
			int l=0,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(mid*(mid+1)*d/2<=m){
					l=mid+1;
					ans=mid+1;
				}
				else r=mid-1;
			}
			cout<<ans;
		}
	}
	return 0;
}