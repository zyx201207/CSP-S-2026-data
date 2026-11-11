#include <bits/stdc++.h>

typedef long long ll;

struct node{
	int pt;
	std::vector<int>c;
	int cnt=0;
}a[200010];

int n,m,ans[100];

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i].pt;
		int z=a[i].pt;
		a[i].c.push_back(0);
		while(z!=0){
			a[i].c.push_back(z&1);
			z/=2;
		}
		while(a[i].c.size()<31)
			a[i].c.push_back(0);
	}
	int full=0; 
	for(int i=31;i>=1;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(a[j].c[i]==1&&a[j].cnt==full)
				sum++;
		}
		if(sum>=m){
			ans[i]=1;
			for(int j=1;j<=n;j++){
				if(a[j].c[i]==1&&a[j].cnt==full)
					a[j].cnt++;
			}
			full++;
		}
	}
	ll sum=0,base=1;
	for(int i=1;i<=31;i++){
		if(ans[i])
			sum+=base;
		base*=2LL;
	}
	std::cout<<sum<<"\n";
	return 0;
}
