#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x,ans,a[500005],b[500005];
bool A,B;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=1;
		}
		if(i==2){
			x=a[i]-a[i-1];
		}
		if(i>=2){
			if(a[i]-a[i-1]!=x){
				B=1;
			}	
		}
	}
	x=abs(x);
	if(B==0){
		for(int i=0;i<n;i++){
			if(m>=x*i){
				m-=x*i;
			}else{
				break;
			}
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ll cnt=0;
		for(int j=1;j<=n;j++){
			if(a[i]>=a[j]){
				b[j]=a[i]-a[j];	
			}else{
				b[j]=-1;
			}
		}
		sort(b+1,b+n+1);
		ll x=m;
		for(int i=1;i<=n;i++){
			if(b[i]==-1){
				continue;
			}
			if(x>=b[i]){
				x-=b[i];
			}else{
				break;
			}
			cnt++;
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
} 