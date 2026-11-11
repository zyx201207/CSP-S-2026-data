#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
stack<int> g[M];
int jx[M];
int sx[M];
long long ans,k,l;
stack<int> s;
int pd(long long x,int y){
	int j = 0;
	while(x){
		if(x & 1){
			g[y].push(1);
		}else{
			g[y].push(0);
		}
		x >>= 1;
		j++;
	}
	return 30 - j;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		long long c;
		cin>>c;
		int h = pd(c,i);
		for(int j = 0;j < h;j++){
			g[i].push(0);
		}
	}
	for(int i = 1;i <= 30;i++){
		for(int j = 1;j <= n;j++){
			int t = g[j].top();
			g[j].pop();
			if(t){
				jx[j] = 1;
			}
			if(jx[j] == 1){
				s.push(j);
			}
			jx[j] += jx[j - 1];
		}
		if(jx[n] >= m){
			k++;
			while(!s.empty()){
				int v = s.top();
				if(k == 1){
					sx[v] = 1;
				}else{
					if(sx[v] == k - 1){
						l++;
						sx[v]++;
					}
				}
				s.pop();
			}
			if(k == 1 || l >= m){
				ans += (long long)pow(2,30 - i);
			}
			l = 0;
		}
		for(int j = 1;j <= n;j++){
			jx[j] = 0;
		}
	}
	cout<<ans;
	return 0;
}