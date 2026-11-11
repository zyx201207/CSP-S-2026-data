#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
int main(){
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	long long aw=a.at(n-1);
	for(int i=0;i<m;i++){
		aw=aw & a.at(n-i-1);
	}
	cout<<aw;
	return 0;
}

