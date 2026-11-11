#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long num=a[1];
	long long x=2;
	for(;x<=n;x++){
		if(num==a[x]&&x<n){x++;continue;}
		long long bushu=a[x]-num,w=bushu*(x-1);
		if(w>m)break;
		if(w<=m){
			printf("%lld %lld %lld %lld %lld\n",a[x],num,bushu,bushu*(x-1),m);
			num=a[x];
			m-=(x-1)*bushu;
		}else{
			printf("%lld %lld %lld %lld %lld\n",a[x],num,bushu,bushu*(x-1),m);
			num+=m/(x-1);
			m%=(x-1);
		}
	}
	cout<<x-1;
	return 0;
} 
