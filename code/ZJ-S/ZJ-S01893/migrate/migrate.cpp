#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,dp[N],s[N];
long long d,x[N];
void solve1(){
	cin>>n>>d;int ans=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		dp[i]=0;s[i]=1;
		for(int j=i+1;j<=n;j++){dp[j]=1e9;s[j]=0;
			for(int k=i;k<j&&dp[k]!=dp[j];k++){
				if(dp[j]>dp[k]+1&&x[j]-x[k]<=d){
					dp[j]=dp[k]+1;s[j]=s[k];
				}else if(dp[j]==dp[k]+1&&x[j]-x[k]<=d)s[j]+=s[k];
			}if(s[j]==2)ans++;
		}
	}cout<<ans<<"\n";
}
void solve2(){
	cin>>n>>d;int ans=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	sort(x+1,x+n+1);
	if(d<2*(x[2]-x[1]))cout<<"0\n";
	else{
		int s=d/(x[2]-x[1]);
		cout<<max(0,n-2*s-3)<<"\n";
	}
}
void solve3(){
	cin>>n>>d;int ans=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	sort(x+1,x+n+1);
	int a1=0,a2=0;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d&&!a1)a1=i;
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d)a2=i;
	}
	if(a2-a1+1>2)cout<<"0\n";
	else if(a2==a1){
		cout<<"3\n";
	}else cout<<"2\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--)solve2();
	}else if(c==13||c==14){
		while(t--)solve3();
	}else while(t--)solve1();
	return 0;
}
