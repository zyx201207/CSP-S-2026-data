#include<bits/stdc++.h>
#define int long long
#define si signed
#define endl '\n'
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fp(s) string ssss=s;freopen((ssss+".in").c_str(),"r",stdin);freopen((ssss+".out").c_str(),"w",stdout);
#define rep(i,x,y) for(int i=x;i<=(y);++i)
using namespace std;
const int N=5e5+5;
int a[N];
si main(){
	fp("crystal");
	fst;
	int n,m,l=1,sum=0,ans=0;
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n){
		if(i!=1) sum+=(a[i]-a[i-1])*(i-l);
		while(l<i&&sum>m){
			sum-=a[i]-a[l];
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
} 
