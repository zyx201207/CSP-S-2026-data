#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 500005

int n;
long long m;
long long a[MAXN];
int ans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long cost=0;
	for(int l=1,r=2;r<=n;r++){
		cost+=(a[r]-a[r-1])*(r-l);
		while(cost>m){
			cost-=a[r]-a[l++];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}