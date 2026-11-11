#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll n,m,an,an1,ans;
ll a[500005];
vector<ll> to[500005];
void cry(){
	for(int i=n/2;i>=0;i--){
		for(int j=to[i].size()/2+1;j<to[i].size();j++){
			ll p=m;
			an=0;
			for(int q=j,w=i;p>=0&&q>=0&&w<n;q--,w++){
				p-=to[w][q];
				an++;
			}
			if(an>an1) an1=an;
			if(an<an1) break;
		}
		for(int j=to[i].size()/2+1;j>=0;j--){
			ll p=m;
			an=0;
			for(int q=j,w=i;p>=0&&q>=0&&w<n;q--,w++){
				p-=to[w][q];
				an++;
			}
			if(an>an1) an1=an;
			if(an<an1) break;
		}
		if(ans<an1) ans=an1;
		if(ans>an1) break;
	}
	for(int i=n/2;i<n;i++){
		for(int j=to[i].size()/2+1;j<to[i].size();j++){
			ll p=m;
			an=0;
			for(int q=j,w=i;p>=0&&q>=0&&w<n;q--,w++){
				p-=to[w][q];
				an++;
			}
			if(an>an1) an1=an;
			if(an<an1) break;
		}
		for(int j=to[i].size()/2+1;j>=0;j--){
			ll p=m;
			an=0;
			for(int q=j,w=i;p>=0&&q>=0&&w<n;q--,w++){
				p-=to[w][q];
				an++;
			}
			if(an>an1) an1=an;
			if(an<an1) break;
		}
		if(ans<an1) ans=an1;
		if(ans>an1) return;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int k=a[j]-a[i];
			if(k>m) break;
			to[i].push_back(k);
		}
	}
	cry();
	printf("%lld",ans);
	return 0;
}
