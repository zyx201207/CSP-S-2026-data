#include <bits/stdc++.h>
using namespace std;
int ans,c,t,n,d;
int loc[10005];
void shorest(){
	for(int i=n;i>=0;++i){
		i-d+1>=0;
		ans++; 
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	for(int sk=1;sk<=t;++sk){
		for(int i=1;i<=n;++i){
	    	cin>>loc[i];
		}
		shorest();
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
