#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],ans;
long long read(){
	long long s=0,b=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
	return s*b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		long long cnt=0,l=1,r=i-1;
		while(l<=r){
			long long mid=l+r>>1;
			if((s[i]-s[mid-1]+m)/a[i]>0){
				cnt=max(cnt,min((s[i]-s[mid-1]+m)/a[i],i-mid+1));
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
