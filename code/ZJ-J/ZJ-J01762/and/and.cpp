#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	ans=a[1];
	while(m){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(max(ans&a[i],ans&a[j]),a[i]&a[j]);
			}
		}
		m--;
	}
	cout<<ans<<"\n";
	return 0;
}