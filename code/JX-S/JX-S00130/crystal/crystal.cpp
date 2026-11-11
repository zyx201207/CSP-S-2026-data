#include <bits/stdc++.h>
using namespace std;
long long n,m,z,c;
long long a[500005],b[500005],x[500005],maxn=0,l,r;
bool ckl(long long u,long long v){
    z=x[v]*(v-u+1);
    c=a[v]-a[u-1];
    if(z-c<=m) return true;
    else return false;
}
long long ck(long long w){
     l=1,r=w;
     while(l<r){
		 long long mid=(l+r)>>1;
		 if(ckl(mid,w)) r=mid;
		 else l=mid+1; 
	 }
	 return w-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>x[i];
		a[i]=x[i]+a[i-1];
		b[i]=i*x[i]-a[i];
		maxn=max(ck(i),maxn);
	}
	cout<<maxn;
	return 0;
}
