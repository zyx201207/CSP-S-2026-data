#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(x[j]-x[i]<=d) continue;
				else{
					if((x[j]-x[i])/d==(x[j]-x[i]+d-1)/d) continue;
					if(j-i-1<(x[j]-x[i]+d-1)/d) continue;
					ans+=1;
				}  
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
__builtin_clz
priority_queue
*/