#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],maxx;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long ans=(a[i]&a[i+1]);
		long long t=2;
		while(t<m){
			ans+=(ans&a[i+t]);
			t++;
		}
		maxx=max(maxx,ans);
	} 
	cout<<maxx;
}
