#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN];
void print(deque<int> d){
	cout<<"Deque:";
	while(d.size()){
	cout<<d.front()<<" ";
	d.pop_front();
	}
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long ans=1,presum=0,cnt=1;
	deque<int> dq;
	for(int i=1;i<=n;i++,cnt++){
		presum+=a[i];
		while(a[i]*cnt-presum>m){
			cnt--;
			presum-=dq.front();
			dq.pop_front();	
		}
		dq.push_back(a[i]);
		ans=max(ans,(long long)dq.size());
	}
	cout<<ans;
	return 0;
}