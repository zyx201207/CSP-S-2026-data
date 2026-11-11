#include<bits/stdc++.h>// 一定要打开 
//#define ios ios::sync_with_stdio(false)
//#define tie cin.tie(nullptr),cout.tie(nullptr)
//#include<iostream>

using namespace std;
typedef long long ll;

const int N=1e6+5;

int n;
ll a[N],m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll r=1,ans=0;
	ll sum=0;
	for(int l=1;l<=n;++l){
		while(r<=n&&sum+(a[r]-a[r-1])*(r-l)<=m){
			sum+=(a[r]-a[r-1])*(r-l);
			r++;
		}
		ans=max(ans,r-l);
		if(r>1)
			sum-=(a[r-1]-a[l]);
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}