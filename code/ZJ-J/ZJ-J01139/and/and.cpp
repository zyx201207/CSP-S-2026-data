#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans,a[200005],dp1[2005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=2000){
		for(int i=0;i<=n;i++) dp1[i][1]=max(dp1[i-1][1],a[i]); 
		for(int i=1;i<=n;i++){
			for(int j=2;j<=m;j++){
				if(i>=j) dp1[i][j]=max(dp1[i-1][j],(dp1[i-1][j-1]&a[i]));
			}
		}
		cout<<dp1[n][m];
	}else{
		for(int i=1;i<=n;i++) sum=max(sum,a[i]);
		if(sum<4){
			ans=1;
			for(int i=n;i>=1;i--) ans=ans&a[i];
			cout<<ans;
		}else{
			if(m==n-1){
				ans=1;
				for(int i=2;i<=n;i++) ans=ans&a[i];
				cout<<ans;
			}else cout<<a[n-m+1];
		}
	}
	return 0;
}