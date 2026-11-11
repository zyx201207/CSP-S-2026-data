//周焌灏 SN-S00536
#include <bits/stdc++.h>
using namespace std;

/*
题目：给出一串数字，然后找最符合的中间数
使得经过若干次操作之后，众数的值最大 
思路：先用二分答案，搜出来最符合的那个数 
坑：注意要排序，最适合的数不一定出现在里面 
m要开longlong，记得freopen 
 */

const int N = 5000005;
long long a[N];
long long n;
long long m;
long long l;
long long r;
long long maxx;
long long mid;
long long ans;
long long yong;
long long out;
long long minn = N;

bool check(long long num){
	yong = 0;
	for(long long i = 1;i<=n;i++){
		if(a[i] < num){
			yong += (num - a[i]);
			//cout<<"yong"<<yong<<" ";
		}
	}
	if(yong <= m){
		//cout<<num;
		return true;
	}
	if(yong > m) return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//in
	scanf("%lld%lld",&n,&m);
	for(long long i = 1;i<=n;i++){
		scanf("%lld",&a[i]); 
		maxx = max(maxx,a[i]);
		minn = min(minn,a[i]);
	}
	//cout<<maxx;
	r = maxx;
	l = minn;
	sort(a+1,a+n+1);
	/*
	for(int i = 1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	*/
	//2fen
	//cout<<"二分阶段\n";
	while(l<=r){
		mid = (l+r)/2;
		if(check(mid)){
			//cout<<"mid="<<mid<<" l"<<l<<" r"<<r<<" good "<<"ans="<<ans<<"\n";
			l = mid + 1;
			ans = mid;
		}
		else{
			//cout<<"mid="<<mid<<" l"<<l<<" r"<<r<<" bad  \n";
			r = mid - 1;
		}
	}
	out = 0;
	//cout<<"\n";
	for(long long i = 1;i<=n;i++){
		if(a[i] <= ans) out++;
	}
	//cout<<"ans="<<ans<<" ";
		printf("%lld",out);
	return 0;
}
