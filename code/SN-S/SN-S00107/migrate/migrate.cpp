#include <bits/stdc++.h>

typedef long long ll;

int c,test,n;
ll d,x[2000010];

inline void solve(){
	std::cin>>n>>d;
	for(int i=1;i<=n;i++)
		std::cin>>x[i];
	if(n==1){
		std::cout<<0<<"\n";
		return;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		int j=i+3;
		if(j>n)
			break;
		if(x[i+3]-x[i]<=d)
			continue;
		if(x[i+2]-x[i]<=d&&x[i+3]-x[i+2]<=d&&
		x[i+1]-x[i]<=d&&x[i+3]-x[i+1]<=d)
			sum++;
	}
	std::cout<<sum<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::cin>>c>>test;
	while(test--){
		solve();
	}
	return 0;
}
