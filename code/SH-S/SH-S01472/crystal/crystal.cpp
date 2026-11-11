#include <bits/stdc++.h>
using namespace std;
long long n,m,b;
vector<long long> a;
long long c[500005],d[500005],e;
long long cha(long long p,long long q) {
return d[p]-d[q]-(1+q)*(c[p]-c[q]); }
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	e=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b;
		a.push_back(b);
	}
	sort(a.begin(),a.end());
	c[0]=a[1]-a[0];
	d[0]=c[0];
	int ans=0;
	for(int i=1;i<n-1;i++) {
	c[i]=c[i-1]+a[i+1]-a[i];
	d[i]=d[i-1]+(i+1)*(a[i+1]-a[i]);
	} 
	for(int i=0;i<n-1;i++) if(d[i]<=m) e=i;
	else break;
	for(int i=0;i+e+2<n-1;i++) {
		if(cha(i+e+2,i)<=m) {
			e++;i--;}
	}
	if(e>0) ans=e+2;
	cout<<ans;
	return 0;
} 
