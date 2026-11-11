#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,char> a[200010];
long long len=0,l[200010],r[200010],ans=0;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		len+=a[i].first;
		r[i]=r[i-1]+a[i].first;
		l[i]=r[i-1]+1;
	}
	long long L=1,R=len;
	int lw=1,rw=n;
	while(lw<rw&&L<R){
		if(r[lw]-L+1<R-l[rw]+1){
			if(a[lw].second!=a[rw].second) ans+=r[lw]-L+1;
			R-=r[lw]-L+1;
			L+=r[lw]-L+1;
			lw++;
		}
		if(r[lw]-L+1>R-l[rw]+1){
			if(a[lw].second!=a[rw].second) ans+=R-l[rw]+1;
			L+=R-l[rw]+1;
			R-=R-l[rw]+1;
			rw--;
		}
		if(r[lw]-L+1==R-l[rw]+1){
			if(a[lw].second!=a[rw].second) ans+=R-l[rw]+1;
			L+=R-l[rw]+1;
			R-=R-l[rw]+1;
			rw--;
			lw++;
		}
	}
	cout<<ans;
}
