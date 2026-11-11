#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int ans=-1;
int n,m;
bool check(int x){
	int cnt=0,cost=0;
	bool flag=true;
	for(int i=1;i<x;i++){
		if(cost+a[x]-a[i]>m){
			flag=false;
			break;
		}
		cost+=a[x]-a[i];
		cnt++;
	}
	ans=max(ans,cnt+1);
	return flag;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	clock_t st=clock();
	cin>>n>>m;
	bool xza=true,xzb=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]!=a[i-1]) xza=false;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) xzb=false;
	}
	if(xza){
		cout<<n;
		//cerr<<"xza";
		return 0;
	}
	if(xzb){
		cout<<min(n,m/(a[n]-a[n-1]));
		//cerr<<"xzb";
		return 0;
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)) l++;
		else r--;
		if(double(clock()-st)/CLOCKS_PER_SEC>0.9) break;
	}
	cout<<ans;
	//clock_t end=clock();
	//double sec=double(end-st)/CLOCKS_PER_SEC;
	//if(sec>1) cerr<<"TLE"<<sec<<endl;
	//else cerr<<"AC"<<endl;
	return 0;
}
