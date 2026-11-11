#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct sa{
	long long x,y;
}a[N];
int n,m;
long long mid,l,r,mx,ans=0;
bool as(sa i,sa j){
	return i.y>j.y;
}
bool check(long long x){
	long long sum=-1;
	int ans1=0;
	for(int i = 1;i<=n;i++){
		if(sum==-1&&a[i].x>=x){
			sum=a[i].x;
			ans1++;
		}else{
			long long k=(a[i].x&sum);
			if(k>=x){
				ans1++;
				sum=k;
			}
		}
	}
	if(ans1>=m){
		return 1;
	}else {
		return 0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
/*	while(1){
		int x,y;
		cin>>x>>y;
		cout<<(x&y)<<"\n";
	}*/
	scanf("%lld%lld",&n,&m);
	mx=0;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i].x);
		mx=max(a[i].x,mx);
		a[i].y=0;
		int o=a[i].x,l=1;
		while(o){
			if(o%2==1) a[i].y+=l;
			o/=2;
			l++;
		}
	}
	if(mx==0){
		printf("0\n");
		return 0;
	}
	sort(a+1,a+n+1,as);
	l=0,r=mx;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
