#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,k,flag;
ll x[N],sum[N],minn=0x3f3f3f3f;
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			k=d/(x[2]-x[1]);
			for(int i=2;i<=d;i++){
				ans+=n-(2*k-1);
			}
		}
		if(c==13||c==14){
			for(int i=1;i<=n;i++){
				x[i]-=x[1];
				sum[i]=sum[i-1]+x[i];
				if(abs(sum[i]-(x[i]-sum[i]))<minn){
					minn=abs(sum[i]-(x[i]-sum[i]));
					flag=i;
				}
			}
			if((x[n]-sum[flag-1])<=d){
				if((x[n]-sum[flag-2])>d&&sum[flag+1]>d){
					ans++; 
				}
			}
			else if(sum[flag+1]<=d){
				if(sum[flag+2]>d){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
