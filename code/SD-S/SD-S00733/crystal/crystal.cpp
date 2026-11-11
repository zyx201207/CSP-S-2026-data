#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],l,r,d,c,p=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<n;i++){
		l=i;
		r=n;
		while(l<r){
			c=0;
			d=(l+r+1)/2;
			c=a[d]*(d-i+1)-s[d]+s[i-1];
			if(c>m){
				r=d-1;
			}
			else{
				l=d;
			}
		}
		p=max(p,l-i+1);
	}
	cout<<p;
	return 0;
}
