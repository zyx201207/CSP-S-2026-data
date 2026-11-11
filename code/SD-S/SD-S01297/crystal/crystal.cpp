#include<bits/stdc++.h>
#define ull long long
using namespace std;
ull a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ull n,m,k,ans=1;
	bool f=1;
	cin>>n>>m;
	cin>>a[1];
	if(n==1){
		cout<<1;
		return 0;
	}
	cin>>a[2];
	k=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=k){
			f=0;
		} 
	}
	if(f){
		for(int i=n-1;i>=1;i--){
			if(m>=a[n]-a[i]){
				m-=(a[n]-a[i]);
				ans++;
			}
			else{
				cout<<ans;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	ull l=1,r=1,cnt=0;
	k=1;
	while(r<=n-1){
		r++;
		cnt+=k*(a[r]-a[r-1]);
		while(a[r]==a[r+1]){
			r++;
		}
		while(cnt>m){
			cnt-=(a[r]-a[l]);
			l++;
		}
		k=r-l+1;
		ans=max(ans,k);
	}
	if(r==n){
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}

