#include<bits/stdc++.h>
using namespace std;

long long n,m;
const int N = 500005;
long long num[N];
long long ans = 0;

bool cmp(const int a,const int b){
	return a < b;
}

bool check(int val){
	long long step = 0;
	for(long long i = 0;i < val;i++){
		step += num[val-1] - num[i];
	}
	return step <= m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i = 0;i < n;i++){
		cin>>num[i];
	}
	bool same = true;
	for(long long i = 0;i < n;i++){
		if(num[i] != i+1){
			same = false;
			break;
		}
	}
	if(same){
		int add = 0;
		while(ans <= m){
			add++;
			ans += add;
		}
		cout<<add;
		return 0;
	}
	bool similar = true;
	for(long long i = 2;i < n;i++){
		if(num[i] - num[i-1] != num[i-1] - num[i-2]){
			similar = false;
			break;
		}
	}
	if(similar){
		long long miux = num[1] - num[0];
		int add = 0;
		int x = 0;
		while(ans <= m){
			add += miux;
			x++;
			ans += add;
		}
		cout<<x;
		return 0;
	}
	sort(num,num+n);
	long long l,r;
	l = 0;
	r = n+1;
	while(l < r){
		long long mid = l+(r-l)/2;
		//cout<<mid<<' ';
		if(check(mid)){
			l = mid+1;
		}else{
			r = mid;
		}
	}
	cout<<l-1;
    return 0;
}
