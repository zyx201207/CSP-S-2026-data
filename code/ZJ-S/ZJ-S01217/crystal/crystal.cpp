#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int maxnn=5e3,maxmm=1e8;
long long n,m;
long long a[N];
long long l=1e18,r=-1e18;

int erfen(int xuyao){
	int l1=1,r1=n;
	while (l1<r1){
		int mid=(l1+r1+1)>>1;
		if (a[mid]<=xuyao)l1=mid;
		else r1=mid-1;
	}
	return l1;
}
bool check(int mid){
	for (int i=l;i<=r;i++){
		int x=erfen(i);
		int nowm=m,sum=0;
		for (int j=x;j>=1;j--){
			if (nowm>=(i-a[j])){
				nowm-=(i-a[j]);
				sum++;
			}
			else break;
		}
		if (sum>=mid)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]),r=max(r,a[i]); 
	}
	sort(a+1,a+n+1);
	if (n>maxnn && m>maxmm){
		long long sum=1;
		for(int i=n-1;i>=1;i--){
			if (m>=(a[n]-a[i])){
				sum++;
			}
			else break;
		}
		cout<<sum<<endl;
		return 0;
	}
	int l1=1,r1=n;
	while (l1<r1){
		int mid=(l1+r1+1)>>1;
		if (!check(mid))r1=mid-1;
		else l1=mid;
	}
	cout<<l1<<endl;
	return 0;
} 
