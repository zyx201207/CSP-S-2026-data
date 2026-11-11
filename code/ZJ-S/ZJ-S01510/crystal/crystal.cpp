#include<bits/stdc++.h>
#define N 500050
#define ll long long
using namespace std;
int n;
ll a[N],m;
priority_queue<ll,vector<ll>,greater<ll> > q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	int cnt=1;
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		m-=1ll*(a[i]-a[i-1])*cnt;
		while(m<0&&!q.empty()){
			m+=a[i]-q.top();
			cnt--;
			q.pop();
		}
		cnt++;
		q.push(a[i]);
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
