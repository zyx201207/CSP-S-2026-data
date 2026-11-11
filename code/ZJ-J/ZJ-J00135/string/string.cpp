#include <bits/stdc++.h>
using namespace std;
struct sj{
	long long a;
	char c;
}z[200005];
long long n,l,r,ans,qz[200005],lw,rw,minc,mid;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>z[i].a>>z[i].c;
		qz[i]=qz[i-1]+z[i].a;
	}
	l=1;
	lw=1;
	r=qz[n];
	if(r%2){
		for(int i=1;i<=n;++i){
			if(qz[i]>=r/2+1)qz[i]--;
		}
		r--;
	}
	rw=n;
	while(l<r){
		minc=min(qz[lw]-l+1,r-qz[rw-1]);
		if(z[lw].c!=z[rw].c){
			ans+=minc;
		}
		l+=minc;
		r-=minc;
		if(l>qz[lw]){
			lw++;
		}
		if(r<qz[rw-1]+1){
			rw--;
		}
	}
	cout<<ans;
	return 0;
}