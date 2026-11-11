#include<bits/stdc++.h>
using namespace std;
long long n,nn[100000000*7+3],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>nn[i];
	}
	for(long long i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
			maxn=max(nn[i]&nn[j],maxn);
	}
	cout<<maxn;
	return 0;
}
