#include<bits/stdc++.h>

#define ll long long
#define MAXX 500005

using namespace std;

inline ll read(){
	ll k=0,f=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9' and c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}

inline void write(ll k){
	if(k<0)putchar('-'),k=-k;
	if(k>9)write(k/10),k%=10;
	putchar(k+'0');
}

	ll n;
	ll a[MAXX],cnt1[MAXX],cnt2[MAXX],m;
	
inline bool check(ll m1){
	
	bool ok=false;
	ll sum=0;

	for(ll i=1,j=m1-1;i<n,j<n;i++,j++){
	

			
		if(i==1){
			for(ll k=1;k<m1;k++)
				sum+=cnt1[k]*k;
		
			if(sum<=m){
				ok=true;
				return true;
			}
		}
		
		else{
			sum-=(cnt2[j]-cnt2[i-1]);
			sum+=((m1-1)*cnt1[j]);

			if(sum<=m){
				ok=true;
				return true;
			}
		}
		
	}
	
	if(!ok)return false;
	
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	n=read();
	m=read();
	for(ll i=1;i<=n;i++)
		a[i]=read();
	
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)
		cnt1[i-1]=a[i]-a[i-1];
	

	
	for(ll i=1;i<n;i++)
		cnt2[i]=cnt2[i-1]+cnt1[i];
		

	
	
	ll l=0,r=n,mid=0,ans=0;
	while(l<=r){
		mid=(l+r)>>1;

		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	
	write(ans);
	
	return 0;
}

