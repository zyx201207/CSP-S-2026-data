#include<iostream>
#include<algorithm>
constexpr int N{500001};
int n,ans{0};
long long m,a[N],b[N];

void solve(){
	std::cin>>n>>m;
	for(int i{1};i<=n;++i)std::cin>>a[i];
	std::sort(a,a+n);
	for(int i{1},j{1};i<=n;++i){
		b[i]=b[i-1]+a[i];
		while(a[i]*(i-j)-b[i-1]+b[j-1]>m)++j;
		ans=std::max(ans,i-j+1);
	}
	std::cout<< ans << '\n';
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//std::cin.tie(0),std::cout.tie(0)->sync_with_stdio(0);
	solve();	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
