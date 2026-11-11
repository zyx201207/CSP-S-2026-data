#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],mid,k,cnt,sum,sl,sr,l=1,r,dim,mus;
char c[1000005];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
	}
	if(k<=3000000000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
				sum+=a[i];
			}
		}
		s=" "+s;
		mid=sum>>1;
		for(int i=1;i<=mid;i++){
			if(s[i]!=s[sum-i+1]) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	r=n;
	mid=k>>1;
	while(l<r&&(sl+sr)*3<=k*2&&l<=n/2&&r>n/2){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[r]-=a[l];
				sl+=a[l];
				sr+=a[l];
				a[l]=0;
				l++;
			}
			else{
				a[l]-=a[r];
				sl+=a[r];
				sr+=a[r];
				a[r]=0;
				r--;
			}
		}
		else{
			if(a[l]>a[r]){
				a[r]-=a[l];
				cnt+=a[l];
				sl+=a[l];
				sr+=a[l];
				a[l]=0;
				l++;
			}
			else{
				a[l]-=a[r];
				cnt+=a[r];
				sl+=a[r];
				sr+=a[r];
				a[r]=0;
				r--;
			}
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	for(int i=l;i<=r;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
			mus+=a[i];
		}
	}
	s=" "+s;
	dim=mus>>1;
	for(int i=1;i<=dim;i++){
		if(s[i]!=s[mus-i+1]) cnt++;
	} 
	cout<<cnt;
	return 0;
} 
