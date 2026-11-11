#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,T,n,d,x[2000006],dp[5005][5005];
void solve_baoli(){
	cin>>n>>d;int ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) dp[i][j]=0;
	}
	for(int len=0;len<n;len++){
		for(int l=1;l<=n-len;l++){
			int r=l+len;
			if(len<3) continue;
			int ll=upper_bound(x+1,x+n+1,x[l]+d)-x-1,rr=lower_bound(x+1,x+n+1,x[r]-d)-x;
			if(rr+1==ll || ((dp[ll][r]==2 && dp[ll-1][r]!=2) || (dp[l][rr]==2 && dp[l][rr+1]!=2))){
				dp[l][r]=2;ans++;continue;
			}
		}
	}
	cout<<ans;
}
void solve_A(){
	cin>>n>>d;int t=-3;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]-x[1]>d && t==-3) t=i-2;
	}
	if(t<=1){
		cout<<"0";return;
	}
	int ans=n-t*2+1;
	cout<<max(ans,0ll);
	return;
}
void solve_B(){
	cin>>n>>d;int mid=0,ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d && x[n]-x[i]<=d){
			mid=i;break;
		}
	}
	//cout<<mid<<"\n";
	int a=upper_bound(x+1,x+n+1,x[mid-1]+d)-x-1;
	int b=upper_bound(x+1,x+n+1,x[mid-2]+d)-x-1;
	int c=lower_bound(x+1,x+n+1,x[mid+1]-d)-x;
	int dd=lower_bound(x+1,x+n+1,x[mid+2]-d)-x;
	//cout<<a<<" "<<b<<" "<<c<<" "<<dd<"\n";
	for(int i=1;i<=mid-1;i++){
		if(i<c) ans+=a-b;
		else if(i>=dd) continue;
		else ans+=n-a;
	}
	cout<<ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		if(C<=10) solve_baoli();
		else if(C==11 || C==12) solve_A();
		else if(C==13 || C==14) solve_B(); 
		cout<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

13 1
5 3
-2 -1 0 1 2

13 1
11 5
1 2 3 4 5 6 7 8 9 10 11
*/