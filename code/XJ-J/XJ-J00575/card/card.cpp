#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500050],flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>>a[i+1]) flag=0;
	}
	if(flag=1) cout << n;
	return 0;
}