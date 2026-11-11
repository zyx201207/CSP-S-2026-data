#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i<=b;i++)
#define ll long long
using namespace std;
ll x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int c,T;
	cin>>c>>T;
	if(c == 13|| c == 14){
		while(T--){
			ll n,d,ans = 0;
			cin>>n>>d;
			For(i,1,n) cin>>x[i];
			int idx = 0;
			For(i,1,n){
				if(x[i]-x[1]<=d && x[n]-x[i]<=d){
					idx = i;
					break;
				}
			}
			For(i,1,idx-1){
				auto it = upper_bound(x+1,x+n+1,x[i]+d)-x-1;
				if(it == idx+1){
					ans+=(n-idx-1);
				} 
			}
			cout<<ans<<"\n";
		}
	}
	else{
		while(T--){
			ll n,d,ans = 0;
			cin>>n>>d;
			For(i,1,n) cin>>x[i];
			For(i,1,n){
				For(j,i+2,n){
					if(i!=j&&x[j]-x[i]>d){
						auto it = upper_bound(x+i,x+j+1,x[i]+d)-x-1;
						auto iit = lower_bound(x+i,x+j+1,x[j]-d)-x;
						if(it == iit+1){
							ans++;
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

