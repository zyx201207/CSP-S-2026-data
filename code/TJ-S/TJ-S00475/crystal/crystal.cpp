#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n,0);
	vector<ll> front_sum(n,0);
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	ll head=0,sum=0;
	ll maxn=LLONG_MAX*-1;
	for(int i = 0;i<n;i++){
		auto& tail=i;
		if(i!=0){
			sum+=(a[tail]-a[tail-1])*(tail-head);
		}
		bool l = sum>m&&head<=tail;
		if(sum>m){
			while(l){
				sum-=a[tail]-a[head];
				head++;
				//cerr << "tail is " <<  tail << "head is" << head << "sum is " << sum <<endl;
				l = sum>m&&head<=tail;
			}
		}
		maxn=max(tail-head+1,maxn);
	}
	cout << maxn;
	return 0;
}
