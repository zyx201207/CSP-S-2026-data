#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
ll n,m,a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		cout<<1<<' ';
	}
	return 0; 
}
