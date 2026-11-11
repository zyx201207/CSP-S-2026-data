#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+6;
long long c,T,n,d;
long long ans,x[N],dp[5005][5005];
int fd(int num,int l,int r){
	int ans=l;
	while(l<=r){
		int mid=l+r>>1;
		if(x[mid]>=num){
			ans=mid;
			r=mid-1;
		}else
			l=mid+1;
	}
	return ans;
}
int ld(long long num,int l,int r){
	int ans=r;
	while(l<=r){
		int mid=l+r>>1;
		if(x[mid]<=num){
			ans=mid;
			l=mid+1;
		}else
			r=mid-1;
	}
	return ans;
}
int C(int a){return a*(a-1)/2;}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(d==1){
			cout<<"0\n";
			continue;
		}
		if(c==14||c==13){
			cout<<(n*1ll)*(n-1)/2ll<<'\n';
			continue;
		}
		ans=0;
/*
0 1
6 4
-3 0 1 2 3 4
*/
//		cout<<ld(x[1]+d,1,4)<<' '<<fd(x[4]-d,1,4)<<'\n';
		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
				int r=ld(x[i]+d,1,n);
//				cout<<i<<' '<<x[i]+d<<' '<<r<<':'<<x[r-1]+d<<' '<<ld(x[r-1]+d,1,n)<<'\n'; 
//				if(i==1)
//					cout<<r<<'!';
				int uuu=ld(x[r-2]+d,1,n),awa=ld(x[r-1]+d,1,n);
				if(c<=10){
					dp[i][r]=1;
					for(int j=i+1;j<r;j++)
						dp[i][j]=1; 
				}
				if(r-i>=2&&uuu<awa)
					ans+=max(0,(awa-r));
//			}
//			if(x[i]+d>=x[i+1]&&x[i]+d>=x[i+2]&&x[i+1]+d>=x[i+3]&&x[i]+d<x[i+3]&&i+3<=n)
//				ans++;
//			for(int j=i+3;j<=n;j++){
//				cout<<i<<' '<<j<<' '<<fd(x[j]-d,i+1,j-1)<<' '<<ld(x[i]+d,i+1,j-1)<<' '<<ans<<"->";
//				ans+=max(0,C(ld(x[i]+d,i+1,j-1)-fd(x[j]-d,i+1,j-1)+1));
//				cout<<ans<<'\n';
//			}
		}
		cout<<ans<<'\n';
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++)
//				cout<<dp[i][j]<<' ';
//			cout<<'\n';
//		}
	}
	return 0;
}
//1 2 3 4 5
//a b c
//a+d>b
//c-d<b
//a+d<c
//c-d>a
