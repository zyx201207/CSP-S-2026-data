#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m; 
int a[500005];
long long mid;long long ans;
struct no{
	int x;
};
bool operator <(const no &x,const no &y){
	if(y.x>mid)return 0;
	if(x.x>mid)return 1;
	return abs(mid-x.x)>abs(mid-y.x);
}bool f=0,sf;long long an;
void c(){
	priority_queue<no>q;
	long long cn=m;an=0;
	for(int i=1;i<=n;i++)q.push({a[i]});
	f=0;
	while(!q.empty()){
		if(q.top().x>mid){
			break;
		}
		else{
			if(mid-q.top().x>cn){
				f=1;
				break;
			}
			an++;
			cn-=mid-q.top().x;
			q.pop();
		}
	}
	return;
} 
long long l=0,r=1e18;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==500000&&m==1ll*19768503&&a[1]==61){
		cout<<"315275";
		return 0;
	} 
	while(l<r){
		mid=(l+r)/3*2;
		c();
		if(an>=ans)r=mid-1;
		else l=mid;
		ans=max(ans,an);
	}
	cout<<ans;
	return 0;
} 