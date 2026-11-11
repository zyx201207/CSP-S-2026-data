#include <bits/stdc++.h>
using namespace std;
long long n,m,x;
long long a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie;
	cout.tie;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]
	}
	x=1;
	for(int i=1;i<=n;i++){
		b[x]=a[i];
		for(int j=1;j<=x;j++){
			b[j]=a[i];
			
		}
	}
	
	
	return 0
}