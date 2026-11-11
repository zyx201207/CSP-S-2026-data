#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,cnt=1; 
int a[500010];
map<long long,long long> mp;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==0||n==1){
		cout<<0;
		return 0;
	}
	bool b=true,c=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		ans=max(ans,mp[a[i]]);
		if(i>=2&&a[i]!=a[i-1]+1){
			b=false;
		}
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			c=false;
		}
	}
	if(m==0){
		cout<<ans;
		return 0;
	}else if(b){
		for(int i=1;i<=m;i++){
			m-=i;
			ans++;
		}
		cout<<ans;
		return 0;
	}else if(c){
		while(m-(a[2]-a[1])>0){
			m-=(a[2]-a[1]);
			ans++;
		}
		cout<<ans-1;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	long long h[2]={0},dp[2]={0};
	h[1]=a[1];
	for(int i=1;i<=n;i++){
		if(m<(a[i]-((h[i%2]+i)/i))*i){
			dp[i%2]=dp[(i-1)%2];
		}else{
			dp[i%2]=dp[(i-1)%2]+1;
		}
		h[(i+1)%2]=h[i%2]+a[i+1];
	}
	cout<<dp[n%2];
	return 0;
} 
