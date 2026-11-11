#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==n){
		cin>>ans;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans&=a[i];
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(a[i],ans);
		}
	}
	cout<<ans;	
	return 0;
}
