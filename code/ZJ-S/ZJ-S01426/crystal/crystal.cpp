#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+5;

void open(string s){
	if(!s.size())return;
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
ll n,m;
int ans;
ll a[N],sum[N];
int main(){
	open("crystal");
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int r=1,l=1;
	while(l<=r&&r<=n){
		if((a[r]*(r-l)-sum[r-1]+sum[l-1])<=m)r++;
		else l++;
		int len=r-l;
		ans=max(ans,len);
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
