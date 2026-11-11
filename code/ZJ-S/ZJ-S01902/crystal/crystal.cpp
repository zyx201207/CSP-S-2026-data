#include<bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define pf push_back
#define pof pop_back
#define ft first
#define sd second
#define endl '\n'
using namespace std;
long long n,m;
long long val[500010];
queue<long long> cun; 
long long op[500010];
long long ans[500010];
long long anss=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	sort(val+1,val+n+1);
	cun.push(val[1]);
	ans[1]=cun.size();
	for(int i=2;i<=n;i++){
		op[i]=op[i-1]+1ll*cun.size()*(val[i]-val[i-1]);
		while(!cun.empty()&&op[i]>m){
			op[i]-=(val[i]-cun.front());
			cun.pop();
		}
		cun.push(val[i]);
		ans[i]=cun.size();
	}
	for(int i=1;i<=n;i++){
		anss=max(anss,ans[i]);
		//cout<<ans[i]<<endl;
	}
	cout<<anss;
	return 0;
}
