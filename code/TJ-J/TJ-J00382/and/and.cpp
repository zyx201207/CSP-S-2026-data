#include<bits/stdc++.h>
using namespace std;
long long p[200005],a[200005];
int used[200005];
int n,m;
long long ma;
void dg(int c){
	if(c == m+1){
		long long sum=a[1];
		for(int i=2;i<=m;i++){
			sum = sum & a[i];
		}
		ma = max(ma,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(used[i] == 0){
			used[i] = 1;
			a[c] = p[i];
			dg(c+1);
			used[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	dg(1);
	cout<<ma;
	return 0; 
}
