#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

ll read(){
	ll sig=1,x=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')sig=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return sig*x;
}

ll n,m;
vector<ll>dp(N),a(N),num(N),temp(N);

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
		
	n=read();m=read();

	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a.begin(), a.end());
	dp[1]=0,num[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]-a[i-1])*num[i-1];
		num[i]=num[i-1]+1;
		while(dp[i]>m){
			dp[i]-=(a[i]-a[i-num[i]+1]);
			num[i]--;
		}
	}
	ll maxx=-1;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,num[i]);
	}
	auto end=time(0);
	cout<<maxx<<"\n";
	return 0;
}