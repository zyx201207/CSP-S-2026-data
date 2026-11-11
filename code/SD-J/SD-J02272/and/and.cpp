#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<long long>v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	cout<<v[n-m+1];
	return 0;
} 
