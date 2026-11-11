#include <bits/stdc++.h>
#define LL long long
#define lop(x,l,r,c) for(LL x=(l);((r)-x)*(c)>=0&&(c);x+=(c))
#define the return
#define elif else if
#define in(x) cin>>x;
using namespace std;
LL rd(LL x){
	static mt19937 _(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_int_distribution<LL> Q(1,x);
	the Q(_);
}
const LL N=5e5+12;
LL n,m,a[N],mi,b[N],u;
map<LL,LL> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	lop(i,1,n,1) cin>>a[i];
	sort(a+1,a+n+1);
	lop(i,2,n,1) a[i]-=a[1]; a[1]-=a[1];
	lop(i,1,n,1){
		mp[a[i]]++;
		if(a[i]==i) mi++;
		if(i>1&&i<n&&a[i]-a[i-1]==a[i+1]-a[i]) u++;
	} 
	if(mi==n){
		LL o=0;
		lop(i,1,n,1){
			if(m<i) break;
			m-=i;o++;
		}
		if(o==n) o--;
		cout<<o+1; the 0;
	}
	if(u==n-2){
//		cout<<"u";
		LL o=0,k=a[2]-a[1];
		lop(i,1,n,1){
			if(m<k*i) break;
			m-=i*k;o++;
//			cout<<m<<" "<<k*i<<" "<<o<<"\n";
		}
		if(o==n) o--;
		cout<<o+1; the 0;
	}
	a[0]=a[1]-1;
	lop(i,1,n,1){
		if(a[i]==a[i-1]) continue;
		LL m2=m,sum=0;
		lop(j,i-1,1,-1){
			if(m2<a[i]-a[j]) break;
			m2-=(a[i]-a[j]);sum++;
		}
//		cout<<sum+mp[a[i]]<<" ";
		b[i]=sum+mp[a[i]];
	}
	sort(b+1,b+n+1);
	cout<<b[n];
	the 0;
}