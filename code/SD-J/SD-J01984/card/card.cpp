#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}for(long long i=1;i<=n;i++){
		if(a[i]==a[i+1]) continue;
		else cout<<i<<" ";
	}
		
	return 0;
}

