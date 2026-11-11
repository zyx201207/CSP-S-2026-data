#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s[200005][2],t=1,sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++,t++){
		cin>>a[t]>>c[t];
		sum+=a[t];
		if(c[t]==c[t-1]){
			a[t-1]+=a[t];
			t--;
		}
	}
	t--;
	n=t;
	if(sum%2==0){
		long long l=sum/2,r=sum/2+1,li=0,ri=0,ans=0;
		for(int i=1;i<=n;i++){
			s[i][0]=s[i-1][1]+1;
			s[i][1]=s[i-1][1]+a[i];
			if(s[i][0]<=l&&s[i][1]>=l)li=i;
			if(s[i][0]<=r&&s[i][1]>=r)ri=i;
		}
		while(li>=1&&ri<=n){
			if(l-s[li][0]>s[ri][1]-r){
				if(c[li]!=c[ri]){
					ans+=(s[ri][1]-r+1);
				}
				l-=(s[ri][1]-r+1);
				r+=(s[ri][1]-r+1);
				ri++;
			}
			else if(l-s[li][0]<s[ri][1]-r){
				if(c[li]!=c[ri]){
					ans+=(l-s[li][0]+1);
				}
				l-=(l-s[li][0]+1);
				r+=(l-s[li][0]+1);
				li--;
			}
			else{
				if(c[li]!=c[ri]){
					ans+=(l-s[li][0]+1);
				}
				l-=(l-s[li][0]+1);
				r+=(l-s[li][0]+1);
				li--;
				ri++;
			}
		}
		cout<<ans<<' ';
	}
	if(sum%2==1){
		long long l=(sum+1)/2,r=(sum+1)/2,pi=0,li=0,ri=0,ans=0;
		for(int i=1;i<=n;i++){
			s[i][0]=s[i-1][1]+1;
			s[i][1]=s[i-1][1]+a[i];
			if(s[i][0]<=l&&s[i][1]>=r)pi=i;
		}
		li=ri=pi;
		while(li>=1&&ri<=n){
			if(l-s[li][0]>s[ri][1]-r){
				if(c[li]!=c[ri]){
					ans+=(s[ri][1]-r+1);
				}
				l-=(s[ri][1]-r+1);
				r+=(s[ri][1]-r+1);
				ri++;
			}
			else if(l-s[li][0]<s[ri][1]-r){
				if(c[li]!=c[ri]){
					ans+=(l-s[li][0]+1);
				}
				l-=(l-s[li][0]+1);
				r+=(l-s[li][0]+1);
				li--;
			}
			else{
				if(c[li]!=c[ri]){
					ans+=(l-s[li][0]+1);
				}
				l-=(l-s[li][0]+1);
				r+=(l-s[li][0]+1);
				li--;
				ri++;
			}
		}
		cout<<ans<<' ';
	}
	return 0;
}