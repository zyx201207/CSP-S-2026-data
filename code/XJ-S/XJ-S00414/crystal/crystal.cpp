#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500010],tot,cnt;
long long int ma1,ans,ma,fl;
long long der[500010];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	int f=1;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		if(i>2) {
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f=0;
		}
	}
	if(f==0) {
		sort(a+1,a+n+1);
		for(int i=n; i>=1; i--) {
			if(a[i]==a[i-1]) ma++;
			if(a[i-1]!=a[i]) {
				ma1=max(ma,ma1);
				ma=0;
			}
			cnt=1;
			tot=m;
		long long int r=i-1;
		 
			while(1) {
				if(a[i]-a[r]>tot||r<=0) break;
				fl++;
				cnt++;
				tot=tot-(a[i]-a[r]);
				r--;
			}
			//cout<<cnt<<endl;
			ans=max(ans,cnt);
		}
		if(fl==0){
			printf("0");
			return 0;
		}
		if(m==0) {
			if(ma1>1) {
				ma1++;
				printf("%lld",ma1);
			}
			 else printf("0");
			 return 0;
		} 
		else {
			printf("%lld",ans);
			return 0;
		}
	} 
	else {
		sort(a+1,a+n+1);
		int cc=0,ik=1;
		long long tk=0;
		der[1]=0;
		a[n+1]=a[n];
		for(int i=1; i<=n; i++) {
			if(a[i]!=a[i+1]) {
				ik=0;
			}
			der[i+1]=der[i];
			der[i+1]+=a[i+1]-a[i];
		}
		if(m==0){
			if(ik==1) printf("%lld",n);
			else printf("0");
			return 0;
		}
		for(int i=1; i<=n; i++) {
			if(tk+der[i]>m&&tk!=0) {
				printf("%d",i-1);
				return 0;
			} else tk+=der[i];
		}
		printf("0");
	}
	return 0;
}
