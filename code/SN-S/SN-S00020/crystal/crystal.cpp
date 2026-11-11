#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i*(a[j]-a[j-1])-(a[j-1]-a[j-i-1])<=m){
				ans=i+1;break;
			}
		}
	}
	cout<<ans;
	return 0;
}
