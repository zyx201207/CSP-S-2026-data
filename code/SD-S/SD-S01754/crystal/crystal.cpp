#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,b,a[5000005],m,sum[5000005],ch[5000005];
long long s=0;
int c=0;
int main() {

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	if(n>5000){
		if(a[2]-a[1]==1){
			while(s<=m&&c<=n) {
				s+=(++c);
			}
			cout<<c;
			return 0;
		}else{
			if(a[1]>a[2]){
				while(s<=m&&c<=n){
					s+=(c+=(a[1]-a[2]));
				}
				cout<<c;
			}
			if(a[1]<a[2]){
				while(s<=m&&c<=n){
					s+=(c+=(a[2]-a[1]));
				}
				cout<<c;
			}
		}
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cnt=0;
		memset(ch,-1,sizeof(ch));
		for(int j=1; j<=i; j++) {
			ch[++cnt]=a[i]-a[j];
		}
		sort(ch+1,ch+1+cnt);
		s=0;
		c=0;
		while(s<=m&&c<=i) {
			s+=ch[++c];
		}
		sum[i]=c-1;
	}
	long long maxn=0;
	for(int i=1; i<=n; i++) {
		maxn=max(maxn,sum[i]);
	}
	cout<<maxn;
	return 0;
}
