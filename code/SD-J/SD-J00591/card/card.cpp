#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a,cn[100010],p[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		cn[a]++;
	}
	for(int i=1;i<=m;i++) p[i]=p[i-1]+cn[i];
	for(int i=1;i<=m;i++) cout<<p[i]<<' ';
	return 0;
}
