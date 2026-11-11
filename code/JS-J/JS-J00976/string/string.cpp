#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,k,a[N],d[N],b1,e1,b2,e2,ans,d1,d2,d3,d4;
char c[N];
signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		d[i]=d[i-1]+a[i];
	}
	for (int i=1;i<=n;i++){
		int b=d[i-1]+1,e=d[i-1]+a[i];
		if (b>d[n]/2) break;
		if (e>d[n]/2) e=d[n/2];
		b1=d[n]-b+1;e1=d[n]-e+1;
		
		int b2=1,e2=n;
		while (b2+1!=e2){
			int mid=(b2+e2)>>1;
			if (d[mid]<=e1) b2=mid;else e2=mid;
		}
		int l=b2;
		b2=1,e2=n;
		while (b2+1!=e2){
			int mid=(b2+e2)>>1;
			if (d[mid]>b1) e2=mid;else b2=mid;
		}
		b2=l;
		
		d1=d[b2-1]+1,d2=d[b2-1]+a[b2];
		d3=d[e2-1]+1,d4=d[e2-1]+a[e2];
		if (d2<e1) b2++;
		if (d3>b1) e2--;
		d1=d[b2-1]+1,d2=d[b2-1]+a[b2];
		d3=d[e2-1]+1,d4=d[e2-1]+a[e2];
		if (c[b2]!=c[i]) ans+=(d2-e1+1);
		if (c[e2]!=c[i] && b2!=e2) ans+=(d3-b1+1);
		for (int j=b2+1;j<e2;j++){
			if (c[j]!=c[i]) ans+=a[j];
		}
	}cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
