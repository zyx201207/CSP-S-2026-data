#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+5;

int c,T;
int n;
ll d;
vector<ll>x;
vector<ll>seg;
ll f[N];
ll val[N];

int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&T);
	while(T--){
		x.clear();
		seg.clear();
		memset(f,0,sizeof f);
		memset(val,0,sizeof val);
		ll ans=0;
		
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			ll a;
			scanf("%lld",&a);
			x.push_back(a);
		}
		bool flag=0;
		for(int i=0;i<n;i++){
			ll l=x[i];
			int j=upper_bound(x.begin(),x.end(),l+d)-x.begin()-1;
			if(j>=n-1){
				//printf("%d\n",i);
				if(!flag)flag=1;
				else break;
			}
			if(f[j])continue;
			//printf("%lld %lld\n",i,j);
			seg.push_back(i);
			f[j]=i;
		}
		for(auto it=seg.end()-1;it>=seg.begin();it--){
			int l=*it;
			if(f[l+1]){
				val[f[l+1]]++;
				ans+=val[f[l+1]];
			}
			if(f[l]){
				val[f[l]]+=val[l];
			}
		}
		//for(int i=0;i<n;i++)printf("%lld ",val[i]);
		printf("%lld\n",ans);
	}
	return 0;
} 

