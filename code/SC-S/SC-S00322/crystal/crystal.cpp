#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cnt=1;
	long long ad=0;
	for(int i=2;i<=n;i++){
		ad+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(ad>m){
			ad-=(a[i]-a[i-cnt+1]);
			cnt--;
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}