#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
priority_queue<ll> que;
ll n,m;
ll a,sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		que.push(a);
	}
	ll cnt=m-1;
	sum=que.top();
	que.pop();
	while(cnt--){
	sum&=que.top();	
	que.pop();
	}
	cout<<sum;
	return 0;
}
