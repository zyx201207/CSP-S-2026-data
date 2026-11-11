#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll T,C,n,d,ans,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			if(d>=x[i]-x[1] && d<x[i+1]-x[1] && i+1!=n){
				for(int j=1;j+i<=n;j++){
					ans++;
					if(x[j+i+1]-x[j+i]>d) break;
				}
				break;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
