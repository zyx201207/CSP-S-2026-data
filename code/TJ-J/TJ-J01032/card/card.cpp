#include<bits/stdc++.h>
using namespace std;
long long n,m,tmp,idx=0;
long long l[500005]={};
long long ans[300005]={};
bool f=0;
vector<long long> stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&l[i]);
	}
	for(long long i=1;i<=n;i++){
		stk.clear();
		set<long long> ss;
		for(long long j=i;j<=n;j++){
			f=0;
			idx=0;
			for(long long k=0;j!=i and k<stk.size()-1;k++){
				if(stk[k]==l[j]){
					f=1;
					idx=k;
					break;
				} 
			}
			if(f){
				while(!stk.empty() and stk.size()>idx){
					stk.pop_back();
				}
			}
			stk.push_back(l[j]);
		}
		for(auto j:stk){
			ss.insert(j);
		}
		for(auto j:ss){
			ans[j]+=1;
		}
	}
	for(long long i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
