#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,len;
ll a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		len+=a[i];
	}
	ll sum=0,zuo,you,wei;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(len%2==1){
			if(sum>=len/2+1){
				wei=i;
				you=sum-len/2-1;
				zuo=a[i]-you-1;
				break;
			}
		}else{
			if(sum>=len/2){
				wei=i;
				you=sum-len/2;
				zuo=a[i]-you;
				break;
			}
		}
	}
	bool flag=true;
	ll l=wei,r=wei;
	ll cnt=0;
	if(zuo>=you){
		zuo-=you;
		you=0;
	}else{
		you-=zuo;
		zuo=0;
	}
	if(you>0){
		l--;
		while(a[l]<=you){
			if(c[l]!=c[wei]) cnt+=a[l];
			you-=a[l];
			a[l]=0;
			l--;
		}
		if(c[l]!=c[wei]) cnt+=you;
		a[l]-=you;
		you=0;
		r++;
	}
	if(zuo>0){
		r++;
		while(a[r]<=zuo){
			if(c[r]!=c[wei]) cnt+=a[r];
			zuo-=a[r];
			a[r]=0;
			r++;
		}
		if(c[r]!=c[wei]) cnt+=zuo;
		a[r]-=zuo;
		zuo=0;
		l--;
	}
	while(l>0&&r<=n){
		if(a[l]>a[r]){
			if(c[l]!=c[r]) cnt+=a[r];
			a[l]-=a[r];
			a[r]=0;
			r++;
		}else if(a[l]<a[r]){
			if(c[l]!=c[r]) cnt+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l--;
		}else{
			if(c[l]!=c[r]) cnt+=a[l];
			a[r]=0,a[l]=0;
			l--,r++;
		}
	}
	cout<<cnt;
	return 0;
}
