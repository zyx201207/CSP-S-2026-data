#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],a1[500005],b1[500005],cnt=0;
char c[200005],d[200005],c1[500005],d1[500005];
long long f1,f2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=n;i>=1;i--){
		b[i]=a[n-i+1];
		d[i]=c[n-i+1];
	}
	for(long long i=1;i<=n;i++){
		a[i]+=a[i-1],b[i]+=b[i-1];
	}
	long long r=min(a[1],b[1]),cnt1=1,cnt2=1;
	while(r<=a[n]){
		while(r>a[cnt1]) cnt1++;
		while(r>b[cnt2]) cnt2++;
		a1[++cnt]=r,c1[cnt]=c[cnt1];
		b1[cnt]=r,d1[cnt]=d[cnt2];
		if(a[cnt1]>b[cnt2]) cnt2++;
		else cnt1++;
		if(r==a[n]) break;
		r=min(a[cnt1],b[cnt2]);
	}
	long long x=0;
	for(long long i=1;i<=cnt;i++){
		if(c1[i]!=d1[i]){
			x+=a1[i]-a1[i-1];
		}
	}
	cout<<x/2;
	return 0;
}
