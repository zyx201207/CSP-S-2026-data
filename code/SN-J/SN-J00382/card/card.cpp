#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,b[300005],a[500005];
deque<ll>e[300005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		e[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j=e[a[j]].back()+1){
			b[a[j]]++;
		}	
		e[a[i]].pop_front();
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
//A
