#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5,M=3e5+5;
const int NN=5e3+5;
ll n,m,a[N],b[M];
ll cnt[NN][NN];
vector<int> ju; 
int Find(int len,int x){
	for(int i=0; i<len; i++){
		if(ju[i]==x)return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1; i<=n; i++){//模拟第i局 
		ju.clear();
		for(int j=i; j<=n; j++){//第j张牌 
			if(Find((int)ju.size(),a[j])){//如果出现过 
				int idx=lower_bound(ju.begin(),ju.end(),a[j])-ju.begin();//找下标 
				for(int k=idx; k<j; k++)
					if(!ju.empty())ju.pop_back();//扔牌 
			}
			ju.push_back(a[j]);
		} 
		for(int j=0; j<ju.size(); j++){
			cnt[i][ju[j]]++;
		}
	}
	for(int i=1; i<=m; i++){
		ll ans=0;
		for(int j=1; j<=n; j++){
			ans+=cnt[j][i];
		}
		printf("%lld ",ans);
	}
	return 0;
}
//[0,48] 
//Hello world!
