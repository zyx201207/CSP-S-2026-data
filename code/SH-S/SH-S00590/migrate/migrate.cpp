#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000009],p[5009][5009],f[5009][5009],ans;
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			p[i][j]=0;
			f[i][j]=0;
		}
	}
	ans=0;
	for(int i=1;i<n;i++){
		p[i][i+1]=a[i+1]-a[i]<=d;
	}
	for(int i=n;i>=1;i--){
		for(int j=i-2;j>=1;j--){
			p[j][i]=1e18;
			for(int k=j+1;k<=i;k++){
				if(a[k]-a[j]>d) break;
				p[j][i]=min(p[j][i],p[k][i]+1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(p[i][j]==1){
				f[i][j]=1;
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			if(p[j][i]==0) break;
			for(int k=j-1;k>=1;k--){
				if(a[j]-a[k]<=d&&p[k][i]==p[j][i]+1) f[k][i]+=f[j][i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=f[i][j]==2;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<p[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<ans<<endl;
}
void solve2(){
	cout<<0<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool flag=1;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[2]-a[1]) flag=0;
		}
		if(a[n]-a[1]<=d){
			solve2();
		}else if(n<=5000){
			solve1();
		}else{
			cout<<0<<endl;
		}
	}
}
