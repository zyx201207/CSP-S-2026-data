#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,cnt(0),lenth(0);
long long a[510000];
long long need[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (long long i=1;i<=n-1;i++){
		need[i]=a[i+1]-a[i];
	}
	l=1;
	for (long long i=1;i<=n-1;i++){
		cnt+=need[i]*i;
		if (cnt>m){
			cnt-=need[i]*i;
			break;
		}
		r=i;
	}
	lenth=r-l+1;
	while(r<=n-1){
		cnt-=a[r+1]-a[l];
		cnt+=need[r+1]*lenth;
		l++;r++;
		while(cnt+need[r+1]*(lenth+1)<=m&&r<=n-1){
			cnt+=need[r+1]*(lenth+1);
			r++;
			lenth++;
		}
	}
	cout<<lenth+1<<endl;
	return 0;
}
