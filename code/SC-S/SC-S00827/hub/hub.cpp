#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000000],k,cnt1,cnt2;
int main(){
	long long i;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(11<=c&&12>=c){
		while(t--){
			cin>>n>>d;
			for(i=1;i<=n;i++)scanf("%lld",&a[i]);
			k=a[2]-a[1];
			cnt1=2+(d/k-1)*2;
			cnt2=(a[n]-a[1])/k+1;
			if(k>d/2){
				cout<<0<<endl;
			}else{
				printf("%lld\0",cnt2-cnt1+1);
			}
		}
	}
	return 0;
}