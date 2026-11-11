#include<iostream>
#include<algorithm>
const int N = 5e5+10;
struct nd{
	long long num;
	int cs;
};
using namespace std;
long long n,m;
nd a[N];

bool check(long long mb){
	long long u = 0;
	for(long long i = mb;i >= 1;i--){
		long long o = u;
		u = u + (a[mb].num - a[i].num);
		
		//if(mb == 313234)cout << u << endl;
		if(u > m){
		//cout << u << endl;
		    return false;
			
     	}
		
	}
	
	//cout << u << endl;
	return true;
	
}
long long ed(long long l,long long r){
	while(l < r){
		
		long long mid = (r + l)/2+1;
		//cout << l <<' ' << r << ' ' << mid <<' ' << endl;;
		if(check(mid)){
			l = mid;
		}else {
			r = mid-1;
		}
	}
	return l;
}
bool cmp(nd x,nd y){
	return x.num < y.num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i].num;
		a[i].cs = 0;
		//cout << cnt[a[i]] << ' ';
	}
	//cout << 1;
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n;i++){
		if(a[i].num == a[i-1].num){
			a[i].cs = a[i-1].cs+1;
		}
	}
	long long ans = ed(1,n);
	cout << ans;
	return 0;
}
