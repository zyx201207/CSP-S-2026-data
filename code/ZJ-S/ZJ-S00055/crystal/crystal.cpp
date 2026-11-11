#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
int n,res,ans,sum;LL m,a,la;
map<LL,int>mp;
queue<pair<LL,int> >lst;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a),mp[a]++;
	for(auto i:mp){
		if(!lst.empty()){
			while(m<(i.first-la)*sum){
				if(lst.empty())break;
				pair<LL,int>now=lst.front();
				LL d=(i.first-la)*sum-m;
				if(d<res*(i.first-now.first)){
					int tmp=res;
					res-=d/(i.first-now.first),d-=d/(i.first-now.first)*(i.first-now.first);
					if(d) res--;
					m+=(tmp-res)*(la-now.first),sum-=tmp-res;  
					break;
				}
				lst.pop(),m+=res*(la-now.first),sum-=res,res=lst.front().second;
			}
			if(m<(i.first-la)*sum)continue;
			m-=(i.first-la)*sum;
		}
		else res=i.second;
		lst.push(i),sum+=i.second,ans=max(ans,sum),la=i.first;
	}
	printf("%d",ans);
	return 0;
}