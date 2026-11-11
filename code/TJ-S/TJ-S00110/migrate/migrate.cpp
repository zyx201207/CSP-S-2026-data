#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e6+10;
int c,t;
ll x[M];
inline void f(){
	int n;
	ll d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<=3){
		cout<<"0\n";
		return;
	}
	if(n==4){
		if(x[4]-x[1]<=d){
			cout<<"0\n";
			return;
		}
		if(x[4]-x[2]<=d&&x[3]-x[1]<=d){
			cout<<"1\n";
		}
		else{
			cout<<"0\n";
		}
		return;
	}
	ll ans=0;
	if(c==11||c==12){
		if(x[2]-x[1]>d||x[3]-x[1]>d){
			cout<<"0\n";
			return;
		}
		if(x[4]-x[1]<=d){
			cout<<"0\n";
			return;
		}
		if(x[4]-x[2]<=d&&x[3]-x[1]<=d){
			cout<<n-3<<"\n";
		}
		else{
			cout<<"0\n";
		}
		return;
	}
	if(c==13||c==14){
		for(int i=1;i<=n&&x[i]*2<=x[1]+x[n];i++){
			for(int j=i+2;j<=n;j++){
				if(x[j]*2<x[1]+x[n]){
					continue;
				}
				bool cmp=1;
				for(int k=i;k<j;k++){
					if(x[k+1]-x[k]>d){
						cmp=0;
						break;
					}
				}
				if(!cmp){
					continue;
				}
				ll kd=0;
				for(int k=i+2;k<=j;k++){
					kd+=(x[k]-x[k-2]<=d);
				}
				for(int k=i+3;k<=j;k++){
					kd+=(x[k]-x[k-3]<=d);
				}
				if(kd==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			bool cmp=1;
			for(int k=i;k<j;k++){
				if(x[k+1]-x[k]>d){
					cmp=0;
					break;
				}
			}
			if(!cmp){
				continue;
			}
			ll kd=0;
			for(int k=i+2;k<=j;k++){
				kd+=(x[k]-x[k-2]<=d);
			}
			for(int k=i+3;k<=j;k++){
				kd+=(x[k]-x[k-3]<=d);
			}
			if(kd==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	
	while(t--){
		f();
	}
	
	return 0;
}
