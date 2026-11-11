#include<bits/stdc++.h>
const int M=5*1e5+5;
using namespace std;
int n,m,a[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<n<<' ';
	}
	
	return 0;
}

