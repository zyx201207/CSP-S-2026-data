#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],cha[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cha[1]=0;
	sum[1]=0;
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+cha[i];
	}
	int l=1,r=2;
	int summ=cha[1];
	int max1=0;
	while(l<=r&&r<=n){
		summ+=cha[r]*(r-l);
		while(summ>m){
			summ-=sum[r]-sum[l];
			l++;
		}
		max1=max(max1,r-l+1);
		r++;
	}
	cout << max1;
	return 0;
}