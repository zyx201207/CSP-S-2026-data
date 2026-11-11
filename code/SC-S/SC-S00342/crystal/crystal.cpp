#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll m,a[N],n,sum;
int ans,js;
priority_queue<ll>q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;q.push(-x);
	}
	a[1]=-q.top(),q.pop();js=1;
	for(int i=2,j=1;i<=n;i++){
		a[i]=-q.top();q.pop();
		sum=sum+(ll)js*(a[i]-a[i-1]);js++;
		while(sum>m){
			sum-=(a[i]-a[j]);js--;
			j++;
		}
		ans=max(ans,js);
	}
	cout<<ans;
	return 0;
}