#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5+10;
long long n,m,a[N];
bool cmp(long long x,long long y){
	return x<y;
}
bool check(int sum){
	long long cnt=0;
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) cnt++;
	}
	cnt=cnt+1;
	if(cnt>sum) return true;
	return false;
}
bool judge(){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;long long maxn=0,ans=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
		if(n%2==1){
			long long xiangshu = (a[n]-a[1])/(abs(a[2]-a[1]))+1;
			long long zhongjianxiang = (xiangshu/2)*(abs(a[2]-a[1])) + a[1];
			long long zj = xiangshu/2+1;
			long long gongcha = abs(a[2]-a[1]);
			for(long long i=zj+1;i<=n;i++){
				if(m-(2*(i-zj)*gongcha)>=0) {ans+=2; m-=2*(i-zj)*gongcha;}
				else if(m-(i-zj)*gongcha>=0) {ans++;m-=(i-zj)*gongcha;}
			}
		}
		cout << ans+1;
		if(n%2==0){
			long long xiangshu = (a[n]-a[1])/(abs(a[2]-a[1]))+1;
			long long zjdyx = xiangshu/2;
			long long gongcha = abs(a[2]-a[1]);
			long long zhongjiandiyixiang = ((zjdyx-1)*gongcha)+a[1]; 	
			for(long long i=zjdyx+1;i<=n-1;i++){
				if(m-(2*(i-zjdyx)*gongcha)>=0) {ans+=2; m-=2*(i-zjdyx)*gongcha;}
				else if(m-(i-zjdyx)*gongcha>=0) {ans++;m-=(i-zjdyx)*gongcha;}
			}
			if(m-(a[n]-zhongjiandiyixiang)>=0) ans++;
			cout << ans-9;
		}
		return 0;
}
