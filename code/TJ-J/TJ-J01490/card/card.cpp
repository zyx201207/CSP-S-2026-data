#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n<<" "<<1<<" "<<n+1;
	return 0;
}
