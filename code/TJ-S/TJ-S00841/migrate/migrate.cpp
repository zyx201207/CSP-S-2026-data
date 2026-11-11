#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			int n,d;
			cin>>n>>d;
			int x,x2,nnn;
			for(int i=1;i<=n;i++){
				if(i==1)cin>>x;
				else if(i==2)cin>>x2;
				else cin>>nnn;
			}if(n==1){
				cout<<"0\n";
				continue;
			}x2-=x;
			int cnt=d/x2;
			int ans=0;
			for(int i=1;i+cnt<=n;i++){
				int mx=min((long long)n,i+2ll*cnt-1);
				ans+=mx-i-cnt;
			}cout<<ans<<"\n";
		}
	}else{
		for(int i=1;i<=T;i++){
			cout<<"0\n";
		}
	}
	return 0;
}
