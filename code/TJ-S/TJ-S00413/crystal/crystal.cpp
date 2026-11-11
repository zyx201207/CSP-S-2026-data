#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,m,a[N],b[N],cha[N],b1[N],sum[N];
void merge(int l,int r,int op) {
	if(l>=r) return;
	int mid=l+(r-l)/2;
	int i=l,j=mid+1,tot=l;
	if(op==1) {
		while(i<=mid&&j<=r) {
			if(a[i]<=a[j]) {
				b[tot++]=a[i];
				i++;
			} else {
				b[tot++]=a[j];
				j++;
			}
		}
		while(i<=mid) {
			b[tot++]=a[i];
			i++;
		}
		while(j<=r) {
			b[tot++]=a[j];
			j++;
		}
		for(int x=l; x<=r; ++x) {
			a[x]=b[x];
		}
	} else {
		while(i<=mid&&j<=r) {
			if(cha[i]<=cha[j]) {
				b1[tot++]=cha[i];
				i++;
			} else {
				b1[tot++]=cha[j];
				j++;
			}
		}
		while(i<=mid) {
			b1[tot++]=cha[i];
			i++;
		}
		while(j<=r) {
			b1[tot++]=cha[j];
			j++;
		}
		for(int x=l; x<=r; ++x) {
			cha[x]=b1[x];
		}
	}
}
void mergesort(int l,int r,int op) {
	if(l<r) {
		if(op==1) {
			int mid=l+(r-l)/2;
			mergesort(l,mid,op);
			mergesort(mid+1,r,op);
			merge(l,r,op);
		} else {
			int mid=l+(r-l)/2;
			mergesort(l,mid,op);
			mergesort(mid+1,r,op);
			merge(l,r,op);
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n >>m;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	mergesort(1,n,1);
	int midd=n/2+1;
	for(int i=1; i<=n; ++i) { 
		cha[i]=abs(a[i]-a[midd]);
	}
	mergesort(1,n,2);
	sum[1]=0;
	for(int i=2;i<=n;++i){
		sum[i]=sum[i-1]+cha[i];
	}
	for(int i=1;i<=n;++i){
		if(sum[i]<=m&&sum[i+1]>m){
			cout<<i<<" ";
			return 0;
		}
	}
	cout<<n<<" ";
	return 0; 
}
