#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+5);
	for(int i=0;i<n;i++){
		cin>>a[i];
		cout<<a[i]<<" ";
	}
	int ans=2;
    cout<<ans;
	return 0;
}
