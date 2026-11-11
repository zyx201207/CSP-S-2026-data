#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			long long ans=a[i]&a[j];
			maxx=max(maxx,ans); 
		}
	}
	cout<<maxx;
	return 0;
}

