#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],v[500005],d[500005],m,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	bool f=0;
	for(long long i=1;i<=n;i++) {
		cin>>a[i];s+=a[i];
		if(a[i]!=i) f=1;
	}
	if(!f) {
		long long t=m%n;
		long long i=1,cnt=1;
		while(m!=0){
			m-=i;
			i++;
			cnt++;
		}
		printf("%ld\n",cnt);
		return 0;
	}
	else{
		long long ave=s/n,mi=1e-8;
		for(long long i=1;i<=n;i++) {
			v[i]=a[i]-ave;
			if(d[i]<m) d[i]=d[i-1]+abs(v[i]);
			if(d[i]==m) mi=max(mi,i);
		}
		printf("%ld\n",mi);	
	}
	return 0;
} 