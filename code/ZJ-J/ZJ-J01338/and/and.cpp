#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=n;j>=m;j--){
		ans=a[j];
		for(int i=j-1;i>=j-m+1;i--){
			ans=(ans&a[i]);
		}
		if(ans!=0) break;
	}
	cout<<ans;
	return 0;
}