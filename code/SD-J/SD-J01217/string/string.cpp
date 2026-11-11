#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
long long n;
struct A{
	char s;
	long long num;
}; 
deque<A>S;
unsigned check(){
	long long ans=0;
	while(S.size()>1){
		A a=S.front(),b=S.back();
		S.pop_front();S.pop_back();
		if(a.s!=b.s)ans+=min(a.num,b.num);
		if(a.num>b.num){
			a.num-=b.num;
			S.push_front(a);
		}else{
			b.num-=a.num;
			S.push_back(b);
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		long long i;
		char j;
		cin>>i>>j;
		A a;
		a.num=i;
		a.s=j;
		S.push_front(a);
	}
	cout<<check();
	return 0; 
}

