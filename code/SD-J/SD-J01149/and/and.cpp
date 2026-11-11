#include<bits/stdc++.h>
using namespace std;
const int d=2e5;
long long maxx=-1,ans=1,n,m,a[d+5];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		ans=ans&a[i];
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m!=2){
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=1;i<=m;i++){
			ans&=a[n+1-i];
		}
		cout<<ans;
		return 0;
	}
	else{
		maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	return 0;
}
