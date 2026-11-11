#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
ll n,m,a[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
}
