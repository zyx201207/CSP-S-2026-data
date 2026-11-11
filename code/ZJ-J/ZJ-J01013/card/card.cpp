#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		int ans=0;
		if(a[n]==1){
			cout<<n<<" ";
			for(int i=1;i<=n-1;i++){
				if(a[i]==2) ans++;
			}
			cout<<ans;
		}
		if(a[n]==2){
			for(int i=1;i<=n-1;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans<<" "<<n;
		}
	} 
	return 0;
}
