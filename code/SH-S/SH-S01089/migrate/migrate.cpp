#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000010];
void solve_d(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int diff=x[2]-x[1];
	int ii=d/diff;
//	cout<<ii<<" ";
	if(2*ii-1<=n&&ii>=2)cout<<n-(2*ii-1)<<"\n";
	else cout<<"0\n";
}
void solve_s(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int l=n,r=1;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
			l=min(l,i);
			r=max(r,i);
		}
	}
	cout<<(l-1)*(n-r)<<"\n";
}
int dp[5010][5010];
int skip[5010];
void solve_brute(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		skip[i]=lower_bound(x+1,x+i,x[i]-d)-x;
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
//		cout<<"i="<<i<<"\n";
		for(int j=1;j<=n;j++){
			for(int k=0;k<=n;k++){
				dp[j][k]=0;
			}
		}
		dp[i][0]=1;
//		cout<<dp[i][0]<<"\n";
		for(int j=i+1;j<=n;j++){
			for(int k=max(i,skip[j]);k<j;k++){
				for(int cnt=0;cnt<=n;cnt++){
					if(dp[k][cnt]==0)continue;
					dp[j][cnt+1]+=dp[k][cnt];
				}
			}
		}
//		for(int j=i;j<=n;j++){
//			for(int cnt=0;cnt<=n;cnt++){
//				cout<<dp[j][cnt]<<" ";
//			}
//			cout<<"\n";
//		}
//		cout<<"dp[i][0]="<<dp[i][0]<<"\n";
		for(int j=i+1;j<=n;j++){
			for(int cnt=1;cnt<=n;cnt++){
				if(dp[j][cnt]!=0){
					if(dp[j][cnt]==2)ans++;
					break;
				} 
			}
		}
	}
	cout<<ans<<"\n"; 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			solve_d();
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			solve_s();
		}
		return 0;
	}
	while(t--)solve_brute();
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
