#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	}
	return 0;
}
