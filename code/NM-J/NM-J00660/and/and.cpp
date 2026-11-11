#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long y[50];
long long m2[50],a[200010];
map<long long,int>s;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	m2[0]=1;
	for(long long i=1;i<=40;i++){
		m2[i]=m2[i-1]*2;
	}
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[a[i]]++;
	}
//	for(auto i:s){
//        printf("%lld %lld\n",i.first,i.second);
//	}
	long long ans=0;
	set<long long>cln;
	for(long long i=32;i>=0;i--){
		long long sum=0;
		for(auto j:s){
			if(j.first&m2[i]){
				sum+=j.second;
			}
		}
		if(sum>=m){
//            printf("%lld\n",i);
			ans+=m2[i];
			cln.clear();
			for(auto j:s){
				if(!(j.first&m2[i])){
					cln.insert(j.first);
				}
			}
			for(auto j:cln){
				s.erase(j);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
