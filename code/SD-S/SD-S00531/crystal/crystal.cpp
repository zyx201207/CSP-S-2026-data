//csp-s2026 rp++
//noip2026 rp++
#include<bits/stdc++.h>
#define int long long
#define forr(i,a,n) for(int i=a;i<=n;i++)
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
const int mod=1e9+7;
int a[N],sum[N];
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	forr(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	forr(i,1,n) sum[i]=sum[i-1]+a[i];
	int ans=1,sum2=0;
	int l=1;
	forr(i,1,n){
		while(1){
			int mo=(a[i]-a[i-1])*(i-l);
//			cout<<i<<' '<<l<<' '<<sum2+mo<<'\n';
			if(sum2+mo<=m){
				sum2+=mo;
				break;
			}else{
				sum2-=a[i-1]-a[l];
				l++;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	
	
	return 0;
} 
