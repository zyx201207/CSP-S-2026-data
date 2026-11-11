#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200001],l[200002],sum,r[200001],ans;
char c[200001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r[i]=r[i-1]+a[i];
		l[i]=r[i-1]+1;
		sum+=a[i];
	}
	l[n+1]=sum+1;
	int w=upper_bound(l+1,l+n+1,(sum+1)/2)-(l+1);
	int le=w,ri=w,lw=(sum+1)/2,rw=(sum+2)/2;
	if(rw==r[w]+1) ri++; 
	if(lw==l[w]-1) le--; 
	while(le>=1&&ri<=n&&lw>=1&&rw<=sum){
		if(lw-l[le]>r[ri]-rw){
			if(c[le]!=c[ri]) ans+=l[ri+1]-rw;
			ri++;
			lw=lw-(l[ri]-rw);
			rw=l[ri];
		}
		else if(lw-l[le]==r[ri]-rw){
			if(c[le]!=c[ri]) ans+=l[ri+1]-rw;
			le--,ri++;
			lw=r[le];
			rw=l[ri];
		}
		else{
			if(c[le]!=c[ri]) ans+=lw-r[le-1];
			le--;
			rw=rw+(lw-r[le]);
			lw=r[le];
		}
	}
	cout<<ans;
}