#include<bits/stdc++.h>
typedef  long long ll;
using namespace std;
ll a[210000];
char c[210000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	if(r<=1e8){
		string s;
		for(int i=1;i<=n;i++) while(a[i]--) s+=c[i];
		int ans=0;
		for(int i=0,j=r-1;i<j;i++,j--){
			if(s[i]!=s[j]) ans++;
		}
		cout<<ans<<endl;
	}
	else{
		ll rr=r;
		r=n;
		ll l=1,ll=0,ans=0,la=0,ra=n;
		while(l<r){
			if(ll>=rr) break;
			long long len;
			if(l>1||r<n) len=min((ll-la),(ra-rr));	
			else len=min(a[l],a[r]);
			la=ll;
			ra=rr;
			ll=len+ll;
			rr=rr-len;
			if(len==a[r]) r--;
			if(len==a[l]) l++;
			if(c[l]!=c[r]) ans+=len;
		}
		cout<<ans<<endl;
	}
	//wlz_can_fly 
	//wlz shi yi ming lai zi ZJ de Grade 8 child
	//zhe ti bi shang ti nan
	//yu ji 68+
	//zhe shi wo wu nian OI de shou zhan
	//bei ka chu sai si nian ye shi shen le
	//zhu wo he ping mu qian de ren rp++
	
	//example 5 wrong
	return 0;
}