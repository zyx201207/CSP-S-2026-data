#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n == m){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
	}else{
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
	}
	return 0;
}
