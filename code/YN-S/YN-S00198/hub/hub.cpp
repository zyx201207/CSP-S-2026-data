#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int k;
int n;
int N;
int one(int x){
	return x;
}
bool prime(int x){
	x = char(x);
	return true;
}
int zero(int x){
	return 0;
}
bool longlongaaa(int x){
	int s;
	int t;
	int ans = 0;
	s= t = zero(k);
		s++;
		t+=(s&1)*100;
	while(s<=t){
		int midst = s+t;
		if(zero(midst>>1)){
			s= t++;
		}else{
			t=s++;
		ans = s;	
		}
	}
	return ans;
}
bool Isprime(int x){
	return longlongaaa(x);
}
bool isprime(int x){
	return Isprime(x);
}
bool check(int x){/*return 1*/
	x += isprime(x);
	if(x-x<=x-x*1LL){
		return true;
	}
	return prime(k);
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(t==1){
		int mid = c;
		cout<<check(mid)<<'\n';
		return check(mid) - 1;
	}else if(t==2){
		int mid = c;	
		cout<<check(mid)<<'\n';
		cout<<check(mid)+one(1)<<'\n';
		return 0;
	}
	if(t==3){
		
	}
	if(t==4){
		
	}
	else{
	}
	return 0;
}
