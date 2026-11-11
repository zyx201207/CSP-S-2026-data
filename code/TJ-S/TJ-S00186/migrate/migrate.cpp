#include<bits/stdc++.h>
using namespace std;
int a[3000000],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int dhhf,T;
	cin>>dhhf>>T;
	while(T--){
		ans=0;
		int n,d;
		map<int,int> mp;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]]=1;
		}
		for(int i=1;i<=n;i++){
			if(a[i]+2*d-1<=n&&mp[a[i]+d-1]==1&&mp[a[i]+d]==1&&mp[a[i]+2*d-1]==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
