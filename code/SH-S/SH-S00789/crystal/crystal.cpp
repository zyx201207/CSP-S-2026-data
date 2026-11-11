#include<bits/stdc++.h>
using namespace std;
long long check(long long a,long long b,long long c[],long long d){
	vector<pair<long long,long long>>e;
	long long f=0;
	while(f<a){
		long long g=f,h=a-1;
		while(g<h){
			if(c[g+(h-g+1)/2]==c[f]){
				g=g+(h-g+1)/2; 
			}
			else{
				h=g+(h-g+1)/2-1;
			}
		}
		e.push_back({f,g});
		f=g+1;
	}
	long long g[e.size()]={},h=0,p=0,q[e.size()]={};
	for(long long i=e.size()-1;i>=0;i--){
		q[i]=p;
		g[i]=h+q[i]*e[i].second-e[i].first+1);
		h=g[i];
		if(i){
			p=(c[e[i].second]-c[e[i].first-1]);
		}
	}
	long long m[e.size()]={},n=0;
	for(long long i=0;i<e.size();i++){
		m[i]=n+(e[i].second-e[i].first+1);
		n=m[i];
	}
	for(long long i=d-1;i<e.size();i++){
		long long o=e[i].second-e[i].first+1;
		if(i){
			if(g[i-1]-g[i]){
				long long k=0,l=i;
				while(k<l){
					if(g[k+(l-k)/2]-g[i]<=b){
						l=k+(l-k)/2;
					}
					else{
						k=k+(l-k)/2+1;
					}
				}
				if(k){
					o+=(m[i-1]-m[k-1]+(b-(g[k]-g[i]))/q[k-1]);
				}
				else{
					o+=m[i-1];
				}
			}
			else{
				o+=b/q[i-1];
			}
			if(o>=d){
				return 1;
			}
			continue;
		}
		if(o>=d){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long c[a];
	for(long long i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a);
	long long d=1,e=a;
	while(d<e){
		if(check(a,b,c,d+(e-d+1)/2)){
			d=d+(e-d+1)/2;
		}
		else{
			e=d+(e-d+1)/2-1;
		}
	}
	cout<<d;
	return 0;
}
