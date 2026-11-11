#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
long long n,m,sum=0,s,k,t;
long long a[MAXN];
bool cha=true;
long long ans;
long long dp[MAXN],dp2[MAXN];
bool cha2=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]!=i){
			cha=false;
		}
	}
	long long cnt=sum/n;
	long long zhi=a[2]-a[1];
	long long minm=1e6;
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=zhi){
			cha2=false;
		}
	}
	sort(a+1,a+1+n);
	dp[1]=1;
	dp[2]=2;
	dp2[2]=2;
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1]+i-1;
		dp2[i]=dp2[1-1]+(i-1)*zhi;
	}
	if(cha==true&&cha2==true){
		for(int i=1;i<=n;i++){
			if(m>=dp[i]&&m<dp[i+1]){
				s=i;
			}
		}
		if(n>=s){
			cout<<s;
		}else{
			cout<<n;
		}
	}else if(cha2==true&&cha==false){
		for(int i=1;i<=n;i++){
			if(m>=dp2[i]&&m<dp2[i+1]){
				k=i;
			}
		}
		cout<<min(n,k);
	}else{
		for(int i=1;i<=n;i++){
			if(abs(a[i]-cnt)<minm){
				minm=abs(a[i]-cnt);
				t=a[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(abs(t-a[i])<=m){
				ans+=(abs(t-a[i]));
				m-=abs(t-a[i]);
			}
		}
	}
	
	return 0;
}
