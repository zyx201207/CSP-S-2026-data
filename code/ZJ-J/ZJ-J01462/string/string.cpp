#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,a[N],sum[N],l,r,now,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	l=1;
	r=n;
	now=1;
	while(now<sum[n]-now+1)
		if(sum[l]-now+1<sum[n]-sum[r-1]-now+1){
			if(c[l]!=c[r]) ans+=sum[l]-now+1;
			now=sum[l]+1;
			l++;
		}else if(sum[l]-now+1==sum[n]-sum[r-1]-now+1){
			if(c[l]!=c[r]) ans+=sum[l]-now+1;
			now=sum[l]+1;
			l++;
			r--;
		}else{
			if(c[l]!=c[r]) ans+=sum[n]-sum[r-1]-now+1;
			now=sum[n]-sum[r-1]+1;
			r--;
		}
	cout<<ans;
	return 0;
}