#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int x[N];
vector<int>a,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		a.push_back(x[i]);		
	}
	long long ret=0;
	for(int i=30;i>=0;i--){
		int rt=0;
		for(auto v:a){
			if((1<<i)&v){
				rt++;
			}
		}
		if(rt>=m){
			b.clear();
			for(auto v:a){
				if((1<<i)&v){
					b.push_back(v);
				}
			}
			a.clear();
			for(auto v:b){
				a.push_back(v);
			}
			ret+=(1<<i);
		}
	}
	printf("%lld",ret);
	return 0;
}
/*
 4 2
3 15 12 12
*/
