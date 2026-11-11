#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2 && n<=2000){
		for(int i=1;i<n;i++){
			for(int j=i+1,v;j<=n;j++){
				v=a[i]&a[j];
				ans=max(ans,v);
			}
		}
	}else if(m==n-1){
		for(int i=1,v;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				v&=a[j];
			}
			ans=max(ans,v);
		}	
	}else if(m==n){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
