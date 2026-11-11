#include<bits/stdc++.h>//mergesort is waiting---complete
using namespace std;
long long int n,m,a[510000],sum[510000],add,len=1,maxl,b[510000];
void msort(int l,int mid,int r){
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			b[k++]=a[i++];
		}
		else{
			b[k++]=a[j++];
		}
	}
	while(i<=mid){
		b[k++]=a[i++];
	}
	while(j<=r){
		b[k++]=a[j++];
	}
	for(int o=l;o<=r;o++){
		a[o]=b[o];
	}
}
void merge(int l,int r){
	if(l==r) return;
	else{
		int mid=(l+r)>>1;
		merge(l,mid);
		merge(mid+1,r);
		msort(l,mid,r);
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	sort(a+1,a+1+n);
	merge(1,n);
	int l=0;
	
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++){
		long long int t=a[i+1]-a[i];
		if(add+(len)*t>m){
			maxl=max(len,maxl);
			if(t>m){
				add=0;
				l=i+1;
				len=0;
			}
			else{
				while(add+(len)*t>m){
					add-=(sum[l+len-1]-sum[l]);
					len--;
					l++;
				}
				add+=len*t;
				len++;
			}
		}
		else{
			add+=(len)*t;
			len++;
		}
	}
	maxl=max(len,maxl);
	cout<<maxl;
	return 0;
}
/*

5 8
-3 -1 2 2 7
2  3  0 5 -7
2  5  5 10 


2  8  8 3+3*15=
2  2+2*3   2+2*3+4*5


*/
