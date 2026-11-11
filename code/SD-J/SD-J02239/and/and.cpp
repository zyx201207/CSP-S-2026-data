#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define ll long long
#define endl '\n'
ll a[114514],ans,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
	for(int i=0;i<(1<<n);i++){
		sum=LLONG_MAX;
		bitset<20>z(i);
		for(int l=0;l<n;l++){
			if(a[l+1]*(int)z[l]>0)
				sum=sum&(a[l+1]*(int)z[l]);
		}
		if(z.count()==p) ans=max(ans,sum);
		//reverse(s.begin(),s.end());
	}
	cout<<ans;
	}
	else if(p==1){
		ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(p==n){
		ans=LLONG_MAX;
		for(int i=1;i<=n;i++) ans=ans&a[i];
		cout<<ans;
	}
	else if(p==2){
		for(int i=1;i<=n;i++){
			for(int l=1;l<=n;l++){
				if(i!=l) ans=max(ans,a[i]&a[l]);
			}
		}
		cout<<ans;
	}
	else if(n-1){
		sum=LLONG_MAX;
		for(int i=1;i<=n;i++){
			for(int l=1;l<=n;l++){
				if(i!=l) sum=sum&a[i];
			}
			ans=max(sum,ans);
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+1+n);
		ans=n-p+1;
		cout<<ans;
	}
	return 0;
}

