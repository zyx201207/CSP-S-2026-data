#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll num,stop;
};
int c,t;
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ll n,d,l=1,b,ans=0,answer=0;
		scanf("%lld%lld",&n,&d);
		vector<node>a;
		scanf("%lld",&b);
		a.push_back({0,0ll,0ll});
		a.push_back({0,0ll,0ll});
		for(int i=2;i<=n;i++){
			scanf("%lld",&b);
			a.push_back({b,N});
			while(b-a[l].num>d) l++;
			for(int i=j=l;j<i;j++){
				if(a[j].step+l<a[i].step) a[i].step=a[j].step+1,ans=1;
				else if(a[j].step+1=a[i].step) ans++;
				else break;
			}
			answer+=(!(ans%2)&&ans);
		}
		printf("%d/n",answer);
	}
	return 0;
}
