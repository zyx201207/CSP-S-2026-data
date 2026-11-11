#include <bits/stdc++.h>
using namespace std;

long long n,m,sum = 0;
long long p[3000000];
bool vs[3000000];

void dfs(long long tag,long long s,long long stp){
	if(stp == m){
		sum = max(sum,s);
		return;
	}
	vs[tag] = 1;
	for(int i = 0;i < n;++i){
		if(vs[i] == 0){
			dfs(i,p[i]&s,stp+1);
		}
	}
	vs[tag] = 0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;++i){
		cin >> p[i];
	}
	for(int i = 0;i < n;++i){
		dfs(i,p[i],1);
	}
	cout << sum; 
	return 0;
}
