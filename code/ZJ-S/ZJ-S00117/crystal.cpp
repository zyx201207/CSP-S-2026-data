#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N];

struct node{
	vector<ll>q;	
};
vector<pair<int,int>>p;
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.second-x.first+1<=y.second-y.first+1;
}
ll cf(int x,int y){
	ll s=0;
	for(int i=x;i<y;i++){
		s+=a[y]-a[i];
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			if(n-i>maxn){
				for(int j=n;j>=i+1;j--){
					if(j-i+1>maxn){
						maxn=j-i+1;
					}
					if(j-i+1>m||a[j]-a[i]>m){
						continue;
					}
					if(cf(i,j)<=m){
						p.push_back({i,j});
						break;
					}
				}
			}else{
				continue;
			}
		}
	
		sort(p.begin(),p.end(),cmp);
		cout<<p[p.size()-1].second-p[p.size()-1].first+1<<endl;
	}else{
		ll s=0;
		if(a[2]-a[1]==1){
			for(int i=1;i<=n;i++){
				s+=i;
				if(s>m){
					cout<<i;
					return 0;
				}else if(s==m){
					cout<<i+1;
					return 0;
				}
			}
		}
	}
	
	return 0;
}