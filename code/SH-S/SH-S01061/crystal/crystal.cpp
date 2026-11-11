#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N];
int n;ll m;
bool check(int x){
	ll cost=0;
	for(int i=1;i<x;i++){
		cost+=(a[x]-a[i]);
	}
	if(cost>m)return 0;
	else return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int res=-1;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			res=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<res;
	return 0;
}
//qwq

