#include<bits/stdc++.h>
using namespace std;
typedef long long L;
L n,m,a[500005],maxx,minn=1e18;
int num;
L t[500005];
bool check(L x){
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++){
		t[i]=abs(a[i]-x);
	}
	sort(t+1,t+1+n);
	int i=1;
	L sum=0;
	while(sum<=m&&i<=n){
		sum+=t[i++];
	}
	sum-=t[i];
	num=max(num,i-2);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=minn;i<=maxx;i++) check(i);
	cout<<num;
	return 0;
}

