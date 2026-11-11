#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510000];
long long minn=0x3f3f3f3f,maxx,maxxn,flag,d;
priority_queue<long long>pq;
int main() {
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	//printf("0");
	d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=1){
			flag=1;
		}
	}
	sort(a+1,a+n+1);
	if(!flag) {
		if(m>=n*(a[n]-a[1])/2) {
			printf("%lld",n);
		} else {
			long long sum=0,cnt=0;
			for(int i=n; i>=1; i--) {
				sum+=a[n]-a[i];
				if(sum>m) {
					break;
				}
				cnt++;
			}
			printf("%lld",cnt);
		}
	} else {
		for(long long i=minn; i<=maxx; i++) {
			long long sum=0,cnt=0;
			for(int j=1; j<=n; j++) {
				if(a[j]<=i) {
					pq.push(-(i-a[j]));
				}
			}
			while(!pq.empty()&&sum<=m) {
				sum+=(-pq.top());
				if(sum>m){
					break;
				}
				cnt++;
				pq.pop();
			}
			maxxn=max(maxxn,cnt);
			while(!pq.empty()) {
				pq.pop();
			}
		}
		//cout<<maxx<<" "<<minn<<"\n";
		printf("%lld",maxxn);
	}

	return 0;
}
