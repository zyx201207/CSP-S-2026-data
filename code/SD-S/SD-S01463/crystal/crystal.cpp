#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],q[500005],s,ma=1,i,d[2000000000005],z,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
		q[i]=a[i];
		if(a[i]>=0) d[a[i]]++;
		else d[a[i]+1000000000000]++;
	}
	sort(a,a+n);
	sort(q,q+n);
	i=0;
	while(1){
		if(d[i]>=ma){
			ma=d[i];
			if(i<1000000000000) x=i;
			else x=-1*(i-1000000000000);
		}
		if(i==2000000000000) break;
	}
	if(ma==1) s=a[n/2];
	for(i=0;i<n;i++){
		if(a[i]!=x){
			s+=x-a[i];
			q[i]=x;
		}
		if(s>=x){
			break;
		}
	}
	for(i=0;i<n;i++){
		if(q[i]==x){
			z++;
		}
	}
	cout<<z;
	return 0;
}
