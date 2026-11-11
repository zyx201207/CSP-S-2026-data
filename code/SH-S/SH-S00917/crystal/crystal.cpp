#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
ll n,m,ans;
ll a[N],last_num=2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5009||a[n]<=109){
		a[n+1]=a[n];
		for(ll i=n;i>=2;i--){
			m+=(last_num-1)*(a[i+1]-a[i]);
			for(ll j=i-last_num+1;j>=1;j--){
				m-=a[i]-a[j];
				if(m<0){
					m+=a[i]-a[j];
					last_num=i-j;
					break;
				}
				if(j==1){
					cout<<max(i,ans)<<endl;
					return 0;
				}
			}
			ans=max(ans,last_num);
		}
		cout<<ans<<endl;
		return 0;	
	}
	else if(a[2]-a[1]==a[n]-a[n-1]&&a[2]-a[1]==a[n-1]-a[n-2]){
		ll d=a[2]-a[1];
		float sol=(1+sqrt(1+8*m/d))/2;
		ans=floor(sol);
		cout<<ans<<endl;
		return 0;
	}
	else{
		a[n+1]=a[n];
		for(ll i=n;i>=2;i--){
			m+=(last_num-1)*(a[i+1]-a[i]);
			for(ll j=i-last_num+1;j>=1;j--){
				m-=a[i]-a[j];
				if(m<0){
					m+=a[i]-a[j];
					last_num=i-j;
					break;
				}
				if(j==1){
					cout<<max(i,ans)<<endl;
					return 0;
				}
			}
			ans=max(ans,last_num);
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
} 
