#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n<<" "<<a[1]<<" "<<m;
	return 0;
}
