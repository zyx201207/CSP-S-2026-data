#include<bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int k[maxn],v[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,e;
	cin>>n>>m;
	int u = 1;
	for(int i = 1;i <= n;i++){
		cin>>k[i];
	}
	sort(k,k+n);
	v[0] = 4e16;
	for(int i = 1;i <= n;i++){
		v[i] = k[i+1]-k[i];
		e = min(v[i],v[i-1]);
	}
	sort(v,v+n);
	int x = 0,l = 0;
	for(int i = 1;i <= n;i++){
		x = x+v[i];
		l = m-x;
		if(l == 0){
			u++;
			break;
		}
		else if(l > 0){
			u++;
			continue;
		}
		else{
			break;
		}
	}
	cout<<u;
	return 0;
}
