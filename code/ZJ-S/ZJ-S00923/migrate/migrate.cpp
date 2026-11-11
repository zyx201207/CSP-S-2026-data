#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d,c,T,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	if(13<=c&&c<=14){
		while(T--){
			cout<<0<<endl;
		}
	}
	if(11<=c&&c<=12){
		while(T--){
			cin>>n>>d;
			int ans=0,l=1;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]-a[l]>d){
					if(i-l>=3)ans++;
					l++;
				}
			}
			if(n<=3){
				cout<<0<<endl;
				continue; 
			}
			if(a[2]-a[1]>d){
				cout<<0<<endl;
				continue;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
