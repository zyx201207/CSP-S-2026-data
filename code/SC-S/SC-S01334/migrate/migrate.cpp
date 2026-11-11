#include<iostream>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
template<typename Tp=int>
Tp getint(){
	Tp f=1,k=0;
	char c;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())k=k*10+c-'0';
	return f*k;
}
void solve(){
	int n=getint(),d=getint();
	vector<int> x(n+5),is(n+5);
	for(int i=1;i<=n;i++){
		x[i]=getint();
	}
	for(int i=1;i<=n-3;i++){
		if(x[i+1]-x[i]<=d&&x[i+3]-x[i+1]<=d&&
			x[i+2]-x[i]<=d&&x[i+3]-x[i+2]<=d&&
			x[i+3]-x[i]>d){
			is[i]=true;
		}
	}
	vector<int> st;
	for(int i=1;i<=n-3;i++){
		if(is[i]){
			st.push_back(i);
			//cout<<i<<' ';
		}
	}
	//cout<<'\n';
	int cnt=0,len=st.size();
	for(int i=0;i<len;i++){
		int l,r;
		for(l=st[i]-1;l>=1;l--){
			if(is[l]||x[l+1]-x[l]>d)break;
		}
		for(r=st[i]+4;r<=n;r++){
			if(is[r]||x[r]-x[r-1]>d)break;
		}
		cnt+=is[i+1]||is[i+2]||is[i+3]?
		1:(st[i]-l)*(r-st[i]-3);
	}
	cout<<cnt<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
} 