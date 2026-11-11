#include<bits/stdc++.h>
using namespace std;
const int Max=5e5+5;
long long n,m;
long long a[Max];
long long maxx=-0x3f3f3f3f;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		long long t=0,sum=0;
		for(long long j=i-1;j>=1;j--){
			t=a[i]-a[j];
			sum+=t;
			t=j;
			if(sum>m){
				break;
			}
		}
		if(t==i-1){
			maxx=max(maxx,(long long )(0));
			continue;
		}
		maxx=max(maxx,i-t);
	}
	cout<<maxx+1;
	return 0;
}