#include<cstdio>
#include<algorithm>
#define int long long
#define MAXN 500100
inline int min(int a,int b){return a<b?a:b;}
int n,m;//long long 9e18 attention over limit
int a[MAXN],cf[MAXN];
bool check(int len){
	if(len==1)return true;
	int sum=0,ans=0;
	for(int i=1;i<len;i++){
		sum+=i*cf[i];
	}
	ans=sum;
	for(int i=len;i<n;i++){
		sum-=a[i]-a[i-len+1]; //cf[i-len+1]+.....+cf[i-1] len-1 
		sum+=(len-1)*cf[i];
		ans=min(ans,sum);
	}
	if(ans<=m)return true;
	else return false;
	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<n;i++)cf[i]=a[i+1]-a[i];
	int L=1,R=n;
	while(L<R){
		int mid=(L+R+1)/2;
		if(check(mid)){//success
			L=mid;
		}
		else{//fail
			R=mid-1;
		}
	}
	printf("%lld",L);
	return 0;
}/*
1 5 7 12 90
1 5 5 5 6

1 2 4 8 9
1 2 4 1
len=4
1*1+2*2+3*4
1    2    3   4
-1*1-1*2-1*4+3*1
1*2+2*4+3*1
logn

3

two divide the answer

1 5
3
4 5
*/