#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
void sol(){
	int n,m;
	cin>>n>>m;
	vector<int>a;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a.push_back(x);
	}
	sort(all(a));
	int le=0,p=0,ans=0;
	for(int ri=0;ri<n;ri++){
		if(ri!=0)	p+=(a[ri]-a[ri-1])*(ri-le);
		while(p>m && le<=ri){
			p-=a[ri]-a[le];
			le++;
		}
		if(p<=m){
			ans=max(ri-le+1,ans);
			
		}
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	sol();
	
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7


3 6
1 9 9

*/