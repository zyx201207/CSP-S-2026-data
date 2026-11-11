#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],l,s[200005],ans;
char c[200005];
ll find(ll x){
	ll le=1,ri=n;
	while(le<=ri){
		ll mid=(le+ri)/2;
		if(s[mid]<x){
			le=mid+1;
		}else{
			ri=mid-1;
		}
	}
	if(s[le]<x){
		return -1;
	}
	return le;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		s[i]=s[i-1]+a[i];
		l+=a[i];
	}
	ll i=1,k=n;
//	cout<<"\n";
	for(;(s[i-1]*2+1)<l;i++){
		ll f=l-s[i]+1,t=l-s[i-1];
		//cout<<ans<<" "<<i<<" ";
		if(s[i]*2>l){
			f=l/2+1;
			if(l%2==0) f++;
		}
		while(s[k]>=f){
			if(c[k]!=c[i]){
				
				if(s[k]>t and s[k-1]<f){
					ans+=t-f+1;
				}else if(s[k]>t){
					ans+=t-s[k-1];
				}else if(s[k-1]<f){
					ans+=s[k]-f+1;
				}else{
					ans+=s[k]-s[k-1];
				}
				//cout<<ans<<" "<<i<<" "<<k<<" "<<s[k]<<" "<<s[k-1]<<"\n";
			}
			k--;
		}
		k++;
		///cout<<ans<<"\n";
	}
	cout<<ans;
}//479681762610
