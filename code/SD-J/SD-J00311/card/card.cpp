#include <bits/stdc++.h>

using namespace std;
int t[200005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);//Мо 
	freopen("card.out","w",stdout);//Мо 
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		cout<<rand()%100;
	}
	
	return 0;
}
