#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
int n;
long long m;
long long a[MAXN];
long long sum[MAXN];
int lowbit(int x){
	return x&-x;
}
void add(int x,long long k){
	while(x<=n){
		sum[x]+=k;
		x+=lowbit(x);
	}
}
long long query(int x){
	long long res=0;
	while(x>0){
		res+=sum[x];
		x-=lowbit(x);
	}
	return res;
}
bool check(int v){
	long long cnt=1e18;
	for(int i=v;i<=n;i++){
		cnt=min(cnt,a[i]*v-(query(i)-query(i-v)));
	}
	if(cnt<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		add(i,a[i]);
	}
	int l=1,r=n+1;
	while(l+1<r){
		//cout<<l<<" "<<r<<endl;
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
}
