#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,T;
int n,d;
ll a[N];
ll ans;
ll road[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=3){
			cout<<0<<'\n';
			continue;
		}
		if(c==11||c==12){
			if(d/(a[2]-a[1])<=1||d*2>=a[n]-a[1]) cout<<0<<'\n';
			else cout<<max(n-(d/(a[2]-a[1])*2)+1,0ll);
			continue;
		}
//		for(int i=1;i<=n-3;i++){
////			if(a[i]-a[i-1]>d){
////				break;
////			}
//			for(int j=i+3;j<=n;j++){
//				if(a[j]-a[i]>d){
//					if(a[j]-a[j-1]>d||a[i+1]-a[i]>d) continue;
//					
//				}
//			}
//		}
	}
	return 0;
}

