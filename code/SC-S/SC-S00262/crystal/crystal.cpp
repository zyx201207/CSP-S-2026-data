#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long mn=0,mem=1,i=0;
	while(i+1<n&&a[i+1]-a[i]+mn<=m){
		mn+=a[i+1]-a[i];
		i++;
		mem++;
	}
	cout<<mem;
	return 0;
}