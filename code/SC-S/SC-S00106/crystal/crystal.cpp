#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],m;
int n;
bool check(int x){
	ll num=a[x];
	ll need=0;
	for(int i=1;i<=x;i++)need+=num-a[i];
	if(need>m)return 0;
	else return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)==1)l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}