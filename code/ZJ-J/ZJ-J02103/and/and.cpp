#include<bits/stdc++.h>
using namespace std;
long long n,m,a,maxn,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		b=a;
		cin >>a;
		maxn=max(a&b,maxn);
	}
}
	cout <<maxn;
	return 0;
}
