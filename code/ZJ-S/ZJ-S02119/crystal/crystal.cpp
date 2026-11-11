#include<bits/stdc++.h>
using namespace std;
long long n,ans=1;
long long a[500005],c[500005],k[500005],m;
inline long long read(){
	int c;c=getchar();long long ans=0,f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	n=read();
	m=read();for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
		k[i]=a[i]*(i-1)-c[i-1];
	}
	for(int i=1;i<=n;i++){
		long long l=1,r=i,mid;
		while(l<r){
			mid=((l+r)>>1)+1;
//			cout<<mid<<" "<<(k[i]-(a[i]*(i-mid)-c[i-mid]))<<endl;
			if((k[i]-(a[i]*(i-mid)-c[i-mid]) )<=m ){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,l);
	}
	printf("%lld",ans);
}
