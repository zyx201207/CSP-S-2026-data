#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=5e5+5;

ll a[N];
ll q[N];
int ans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];

	sort(a+1,a+1+n);

	int l=1,r=0,now=0;

	for(int i=1;i<=n;i++){
		q[++r]=a[i];
		now+=(r-l)*(q[r]-q[r-1]);
		while(now>m&&l<r){
			now-=abs(q[r]-q[l]);
			l++;
		}
		ans=max(r-l+1,ans);
	}

	cout<<ans;

	return 0;
}