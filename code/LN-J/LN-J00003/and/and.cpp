
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(n==m){
		cin>>a[1];
		int ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}		
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j)continue;
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
	}
	cout<<m;
	return 0;
}
