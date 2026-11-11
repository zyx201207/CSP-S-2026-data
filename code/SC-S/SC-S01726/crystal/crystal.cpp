#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],mus;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool f=1;
	mus=a[2]-a[1];
	for(int i=2;i<=n-1;i++){
		if(mus!=a[i+1]-a[i]){
			f=0;
			break;
		}
	}
	if(f){
		for(int i=n;i>=2;i--){
			int tmp=mus*i*(i-1)/2;
			if(m>=tmp){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}	
	int ans=0;
	for(int l=1;l<=n-1;l++){
		for(int r=l+1;r<=n;r++){
			int tmp=sum[r]-sum[l-1],len=r-l+1;
			if(tmp+m>=a[r]*len){
				ans=max(ans,len);
			}
		} 
	}
	cout<<ans<<endl;
	return 0;
}