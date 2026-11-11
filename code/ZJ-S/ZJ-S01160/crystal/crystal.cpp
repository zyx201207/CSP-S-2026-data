#include<bits/stdc++.h>
using namespace std;
const long long inf=0x7fffffff;
int n,m,s=0,a[500002];
long long diff[500002];
long long maxn=-inf;
int i,j,t=0;
int l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	diff[1]=0;
	for(i=2;i<=n;i++){
		diff[i]=a[i]-a[i-1];
	}
	l=1;
	r=1;
	while(r<=n){
		if(s<=m){
			r++;
			s=s+diff[r]*(r-l);
		}
		if(r>n){
			break;
		}
		if(s>m){
			t=r-l;
			if(t>maxn){
				maxn=t;
			}
			s=s-a[r]+a[l];
			l++;
		}
	}
	cout<<maxn;
	return 0;
}
