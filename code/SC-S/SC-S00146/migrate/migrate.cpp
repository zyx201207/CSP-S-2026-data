#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll d,t,n,c,ans,a[N],l=1,r=4;;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool f=false;
		ans=1;
		while(l<=n&&r<=n){
			while(a[r]-a[l]<=d){
				r++;
				if(r-l>3) l++;
				if(r>n){
				f=true;
				break;
			}
		}
		if(f) break;
		if(a[r]-a[l+1]<=d&&a[l+2]-a[l]<=d){
			ans++;
			r++;
		}
		if(r-l>2) l++;
		if(r-l>3) ans++;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}