#include <fstream>
#include <algorithm>
#define maxn 563599
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[maxn];
int xx;
ll costt;
ifstream fin("crystal.in");
ofstream fout("crystal.out");
pair<bool,ll> check(int mid){
	ll cost=0;
	for(int i=1;i<=mid;i++){
		cost+=1LL*(a[mid]-a[i]);
	}
	return {cost<=m,cost};
}
bool check2(int mid){
	ll temp=0;
	for(int i=1;i<=mid;i++){
		temp+=(a[mid]-a[i]);
	}
	return temp<=m;
}
void binary2(int x){
	int l=x,r=n+1;
	while(r-l>1){
		auto mid=(l+r)>>1;
		if(check2(mid)) l=mid;
		else r=mid;
 	}
 	fout<<l<<endl;
}
int main() {
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n+1;
	while(r-l>1){
		auto mid=(l+r)>>1;
		auto flag=check(mid).first;
		auto x=check(mid).second;
		if(flag) l=mid;
		else r=mid;
		costt=x;
	}
	xx=l;
	binary2(l);
}
/*
Oct31==Dec25?
NO!!!
*/