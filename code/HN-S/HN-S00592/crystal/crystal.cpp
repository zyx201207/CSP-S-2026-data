#include<bits/stdc++.h>
using namespace std;

long long n,m,sum,num,a[500005],b[500005];
bool bo=1,boo=1;

bool check(long long x){
	long long t=m;
	for(long long i=1;i<=n;i++){
		if(a[i]>x){
			break;
		}else{
			t-=(x-a[i]);
			if(t<0){
				return 0;
			}
		}
	} 
	return 1;
}

int re(long long x){
	long long t=m;
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		if(a[i]==x){
			cnt++;
		}else if(a[i]>x){
			break;
		}else{
			t-=(x-a[i]);
			if(t<0){
				break;
			}
			cnt++;
		}
	}
	return cnt;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			bo=0;
		}
	}
	
	if(bo==1){	//	特殊性质A 
		long long ans=0;
		for(int i=1;;i++){
			if(m-i<0){
				break;
			}
			m-=i;
			ans++;
		}
		if(ans==0) cout<<1;
		else cout<<ans+1;
		return 0;
	}
	
	int cha=a[2]-a[1];	//	特殊性质B 
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			boo=0;
			break;
		}
	}
	if(boo==1){
		long long ans=0;
		for(int i=abs(cha);;){
			if(m-i<0){
				break;
			}
			m-=i;
			ans++;
			i+=abs(cha);
		}
		if(ans==0) cout<<1;
		else cout<<ans+1;
		return 0;
	}
	
	long long ans=-1e12;
	sort(a+1,a+1+n);
	long long l=-1e12,r=1e12,mid;
	while(l<=r){
		mid=(l+r)/2;
		long long f=check(mid);
		if(check(mid)){
			l=mid+1;
			ans=re(mid);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
