#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m-i>=0){	
		m-=i;
		ans++;
	}
	}
	cout<<ans+1;
return 0;
}
