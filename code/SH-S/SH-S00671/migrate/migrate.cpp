#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=2e6+6;
ll f[N],x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			f[i]=0;
		}
		ll ans=0;
		
		for(int h=1;h<=n;h++){//遍历起点 
			ll pos=h;//最小转移点 
			for(int i=h+1;i<=n;i++){//遍历终点 
				ll mn=0x3f3f,cnt=0;
				//mn为[h,j]中能到i的点中的最少路径数 
				for(int j=pos;j<i;j++){//遍历转移点 
					if(x[i]-x[j]>d){
						pos++;
						continue;
					}
					if(f[j]==mn)cnt++;
					if(f[j]<mn){
						mn=f[j],cnt=1;
					}
					//if(h==1)
					//cout<<j<<i<<' '<<mn<<' '<<cnt<<endl;
				}
				f[i]=cnt;
			}
			for(int i=1;i<=n;i++){
				//cout<<f[i]<<' ';
				ans+=(f[i]==2);
				f[i]=0;
			}
			//cout<<endl;
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
