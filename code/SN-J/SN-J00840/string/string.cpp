//SN-J00840 谢俊哲 西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum=0,ok_sum=0,last,ans=0;
vector<pair<ll,char>> a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	a.resize(n+1);
	for(int i=0;i<n;i++){
		scanf("%lld %c",&a[i].first,&a[i].second);
		sum+=a[i].first;
	}
	last=n-1;
	for(int i=0;i<n&&i<last;){
		if(a[i].second==a[last].second){
			if(a[i].first>=a[last].first){
				a[i].first-=a[last].first;
				--last;
				if(a[i].first==0) ++i;
			}else{
				a[last].first-=a[i].first;
				++i;
			}
		}else{
			ans+=min(a[i].first,a[last].first);
			if(a[i].first>=a[last].first){
				a[i].first-=a[last].first;
				--last;
				if(a[i].first==0) ++i;
			}else{
				a[last].first-=a[i].first;
				++i;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}//rp++
