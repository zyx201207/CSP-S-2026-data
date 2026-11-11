#include <bits/stdc++.h>
using namespace std;
int n;

long long a[100005];
long long m,maxx=0,minn=1e12;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		maxx=max(a[i],a[i-1]);
		minn=min(a[i],a[i-1]);
	}
	sort(a,a+n);
	
	return 0;
}
