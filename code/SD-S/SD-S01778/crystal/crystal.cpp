#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int maxn=5e5+10;
ll n,m,ans=0;
ll a[maxn],s[maxn];
int d=0;
int b[maxn];
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(b[a[i]]!=1){
			d++;
			b[a[i]]--;
		} 
		if(i==1){
			s[i]=0; 
		}else{
			s[i]=a[i]-a[i-1];
		}
	}
	bool bl=true;
	ll sum=s[2];
	for(int i=3;i<=n;i++){
		if(s[i]!=sum){
			bl=false;
			break;
		}
	}
	if(!bl){
		sort(a+1,a+n+1,cmp);
		unique(a+1,a+n+1);
		ll l,s=m;
		if(n%2==0){
			l=n/2;
			ll sum1=0,sum2=0;
			for(ll i=l;i>=1;i--){
				if(m>=a[l]-a[i]){
					m-=(a[l]-a[i]);
					sum1++;
				}else{
					break; 
				}
			} 
			sum2=sum1;
			for(ll i=l+sum1+1;i>=l+1;i--){
				if(s>=a[l+sum1+1]-a[i]){
					s-=a[l+sum1+1]-a[i];
				}else{
					if(i!=l+1){
						sum2--;
						break; 
					}
				}
			}
			ans=max(sum1,sum2);
		}else{
			l=n/2+1;
			ll sum1=0,sum2=0;
			for(ll i=l;i>=1;i--){
				if(m>=a[l]-a[i]){
					m-=(a[l]-a[i]);
					sum1++;
				}else{
					break; 
				}
			} 
			sum2=sum1;
			for(ll i=l+sum1;i>=l;i--){
				if(s>=a[l+sum1]-a[i]){
					s-=a[l+sum1]-a[i];
				}else{
					if(i!=l){
						sum2--;
						break; 
					}
				}
			}
			ans=max(sum1,sum2);
		}
		cout<<ans+d;
	}else{
		ans=1;
		ll x=s[2];
		for(int i=1;i<=n;i++){
			if(m>=(x*i)){
				m-=(x*i);
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
