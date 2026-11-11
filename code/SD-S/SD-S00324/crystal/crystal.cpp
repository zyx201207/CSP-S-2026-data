#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int n,a[500005],l,r;
ll m,pre[500005];
bool check(int k){
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(ll)(i-1)*(a[i]-a[i-1]);
	for(int i=k;i<=n;i++)if(pre[i]-pre[i-k]<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1,r=n;
	while(l<r){
		memset(pre,0,sizeof(pre));
		int mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
/*
I know you WA but I.
I know you WA but I still try.
*/

