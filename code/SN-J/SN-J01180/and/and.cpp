#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Vesperon{
	int n,m,a[200005],mx=-LLONG_MAX,ans=0;
	void work(){
		//Qaaxaap,Pulsar
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=n;i>m;i--){
			ans=(a[i]&a[i-1]);
		}
		cout<<ans; 
	}
}
int main(){
	ios::sync_with_stdio(0);
	return Vesperon::work() ,0;
}
