#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int N=2000010;
int n;
long long d,x[N],rng[N];
map<pair<int,int>,int> mp,tmp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)
			cin>>x[i];
		for(int l=1,r=1;l<=n;++l){
			while(r<=n && x[r]-x[l]<=d)
				++r;
			rng[l]=r-1;
		}
		for(int i=1;i<=n;++i)
			mp[make_pair(i,rng[i])]=1;
		for(int len=2;len<=n;++len){
			for(int i=1;i<=mp.size();++i){
				int x=mp[i];
				int l=x.first.first,r=x.first.second,t=x.second;
				if(r==n)
					continue;
				if(t==1){
					tmp[make_pair(l,rng[r])]++;
					tmp[make_pair(l,rng[r-1])]+=2;
				}
				else if(t==2){
					tmp[make_pair)l,rng[r]]+=2;
				}
			}
			mp.clear();
			for(int i=1;i<=mp.size();++i){
				int x=mp[i];
				if(x.first.second!=n){
					mp[x.first]=x.second;
					if(x.second==2)
						++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
