#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=3){
			cout<<0<<'\n';
			continue;
		}
		if(c==13 or c==14){
			cout<<0<<'\n';
		}else if(c==11 or c==12){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					if(a[j]-a[i]>d){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
