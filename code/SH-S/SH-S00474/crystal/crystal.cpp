#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	
	deque<int> dq;
	int ans=1;
	int num=0;
	long long cost=0;
	for(int i=0;i<n;i++){
		if(num>0) cost+=num*(a[i]-a[dq.back()]);
		num++;
		dq.push_back(i);
		while(cost>m){
			cost-=(a[i]-a[dq.front()]);
			dq.pop_front();
			num--;
		}
		ans=max(ans,num);
	}
	cout<<ans<<"\n";
	return 0;
}
