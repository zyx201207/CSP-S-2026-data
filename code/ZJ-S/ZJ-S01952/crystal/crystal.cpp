#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
const int maxn=5e5+10;
int n;
long long m;
long long a[maxn];
long long b[maxn];
int ans[maxn];
deque<int> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long dis=0;
	for(int i=1;i<=n;i++){
		if(!q.empty()){
			dis+=(a[i]-a[i-1])*( i-q.front() );
		}
		while(!q.empty()&&dis>m){
			dis-=a[i]-a[q.front()];
			q.pop_front();
		}
		ans[i]=q.size();
		q.push_back(i);
	}
	int res=0;
	for(int i=1;i<=n;i++)
		res=max(res,ans[i]);
	cout<<res+1;
} 
