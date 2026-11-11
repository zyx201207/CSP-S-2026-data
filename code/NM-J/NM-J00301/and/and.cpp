#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ll ans=0;
	if(m==1){
		for(int i=1;i<=n;++i){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;++i){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n-1){
		for(int i=1;i<=n;++i){
			ll temp;
			if(i==1)temp=a[2];
			else temp=a[1];
			for(int j=1;j<=n;++j){
				if(j==i)continue;
				temp&=a[j];
			}
			ans=max(ans,temp);
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;++i){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
