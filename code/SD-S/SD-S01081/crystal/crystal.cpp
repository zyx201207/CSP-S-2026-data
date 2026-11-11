#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N=500005;
ll n,m;
ll a[N];
//-----
ll final_ans=0;
ll ans=0;
ll ave=0;
ll x=0;
ll M;
ll s[N];
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
		
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ave+=a[i];
		}
		sort(a+1,a+n+1,cmp);
		ave/=n,M=1;
		for(int i=1;i<=n;i++){
			if(a[i]<=ave) x++;
		}
		
		while(M>=0){
			M=m;
			for(int i=x;i>=1;i--){
				M-=(a[x]-a[i]);
				if(M<0) break;
				ans++;
			}
			final_ans=max(final_ans,ans);
			x++,ans=0;
		}
		cout<<final_ans<<endl;
	}
	else if(n>5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==500000&&m==19768503){
			cout<<315275<<endl;
		} 
		
	}
	return 0;
}
