#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans=1,sum;
int a[N],b[N],k;
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	k=n-1;
	for(int i=n;i>=1;i--){
		sum+=a[i]-a[1];
	}
	sort(a+1,a+n+1,cmp);
	if(n<=5000){
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				int sum=0;
				for(int x=l;x<=r;x++){
					sum+=(a[r]-a[x]);
					
				}
				if(sum<=m){
					ans=max(ans,r-l+1);
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if((a[i]-a[i-1])*i<=m){
				m-=(a[i]-a[i-1])*i;
				ans++;
			}
		}	
	}
	cout<<ans;
	return 0;
} 
