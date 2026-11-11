#include<bits/stdc++.h>
using namespace std;
long long n,m,O=0;
vector<int>a;
int main(){
	freopen("in.card","r",stdin);
	freopen("out.card","w",stdout);
	scanf("%lld%lld",&n,&m);
	a.push_back(0);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		a.push_back(x);
		if(a[i]>a[i-1]){
			O++;
		}
	}
	if(O==n){
		for(int i=1;i<=m;i++){
			cout<<n-i+1<<' ';
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<1<<' ';
	}
	return 0;
}
