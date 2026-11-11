#include<bits/stdc++.h>
using namespace std;
int n,l,r,d,s;
long long z,m;
long long a[500055];
long long b[500055];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=2;i<=n;i++){
		l=s;r=i;
		while(l<r){
			d=(l+r+1)/2;
			z=a[i]*d-b[i]+b[i-d];
			if(z>m)r=d-1;
			else l=d;
		}
		s=l;
	}
	cout<<s;
	return 0;
}
