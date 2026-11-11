#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

ll n,a[N],b[N];
ll m;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll mn=LLONG_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn=min(a[i],mn);
	}
	sort(a+1,a+n+1);
	int giv=0,mx=1;
	if(m==0){
		int ans=1,tmp=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				tmp++;
			}
			else{
				ans=max(ans,tmp);
				tmp=1;
			}
		}
		ans=max(ans,tmp);
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]-=(mn-1);
	}
	for(int i=2,cur=1;i<=n;i++){
		if(a[i]==a[i-1]){
			cur++;
			mx=max(cur,mx);
			continue;
		}
		if(m-(i-giv-1)*(a[i]-a[i-1])>=0){
			cur++;
			m-=(i-giv-1)*(a[i]-a[i-1]);
		}
		else{
			while(m<(i-giv-1)*(a[i]-a[i-1])&&giv<i){
				giv++;
				cur--;
				m+=a[i-1]-a[giv];
			}
			m-=(i-giv-1)*(a[i]-a[i-1]);
		}
		mx=max(cur,mx);
	}
	cout<<mx<<endl;
	return 0;
}
/*
5 8 
-3 -1 2 2 7
*/
