#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mmax,cnt[200005],num;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=m+1;i>0;i--){
		cnt[num]=a[i];
		num++;
	}
	mmax=cnt[0];
	for(int i=0;i<m;i++){
		mmax=mmax&cnt[i];
	}
	cout<<mmax;
	return 0;
}