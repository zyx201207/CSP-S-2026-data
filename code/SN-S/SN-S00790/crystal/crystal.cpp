#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500007],qz[500007];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		qz[i]=qz[i-1]+a[i];
//		cout<<qz[i]<<' ';
	}
	long long l=0,r=1;
	long long sum=0;
	while(r<=n&&l<=n) {
//		cout<<"L"<<" "<<l<<"R "<<r<<" "<<(a[r]*(r-l-1))<<' '<<(qz[r-1]-qz[l])<<endl;
		if((unsigned long long)(a[r]*(r-l-1))-(qz[r-1]-qz[l])<=m) {
			sum=max(sum,r-l);

			r++;
		} else {
			l++;
		}
	}
	cout<<sum;
	return 0;
}
