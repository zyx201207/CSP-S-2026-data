#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
long long a[500044],s[500044];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long z,x;
	z=read();x=read();
	for(int i=1;i<=z;i++){
		a[i]=read();
	}
	sort(a+1,a+1+z);
	for(int i=1;i<=z;i++){
		s[i]=s[i-1]+a[i];
	}
	long long ans=0,res=0;
	for(int i=1;i<=z;i++){
		int l=1,r=i;
		res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=x){
				r=mid-1;
				res=i-mid+1;
			}
			else{
				l=mid+1;
			}
		}
		if(res>ans)ans=res;
	}
	cout<<ans;
	return 0;
}