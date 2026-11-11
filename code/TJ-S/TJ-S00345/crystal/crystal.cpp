#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>vec(n+1);
	for(int i=1;i<=n;i++){
		cin>>vec[i];
	}
	sort(vec.begin()+1,vec.end());
	int cnt=1;
	for(int i=2;i<=n;i++){
		if(cnt*(vec[i]-vec[i-1])<=m){
			m-=cnt*(vec[i]-vec[i-1]);
			cnt++;
		}else {
			cout<<m<<endl;
			break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

