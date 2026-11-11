#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long 
struct node{
	int cnt;
	char c;
};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<node>vec(n+1);
	for(int i=1;i<=n;i++){
		cin>>vec[i].cnt>>vec[i].c;
	}
	vector<node>a;
	int sz=0;
	for(int i=1;i<=n;i++){
		if(a.empty()||vec[i].c!=a[sz-1].c){
			a.push_back(vec[i]);
			sz++;
		}else{
			a[sz-1].cnt+=vec[i].cnt;
		}
	}
	int ans=0;
	for(int l=0,r=sz-1;l<r;){
		int tmp=min(a[l].cnt,a[r].cnt);
		if(a[l].c!=a[r].c)ans+=tmp;
		a[l].cnt-=tmp;
		a[r].cnt-=tmp;
		if(a[l].cnt==0)l++;
		if(a[r].cnt==0)r--;
	}
	cout<<ans<<endl;
	return 0;
} 
