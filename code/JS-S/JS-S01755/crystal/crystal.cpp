#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],b[500005],ans=0;

int f(long long c,long long d){
	long long sum=1;
	for(long long j=1;j<c;j++){
		if(d>=a[c]-a[c-j]) {
			d=d-(a[c]-a[c-j]);
			sum++;
			
		}
		else return sum;
		}
		return sum;
}

int main(){	
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(long long i=1;i<=n;i++){
	cin>>a[i];
}
if(n==1)cout<<2;
sort(a+1,a+n+1);
for(long long i=2;i<=n;i++){
	b[i]=f(i,m);
	if(b[i]>ans)ans=b[i];

}
cout<<ans;
return 0;
}
