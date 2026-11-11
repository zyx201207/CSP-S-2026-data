#include<iostream>
long long c,t,n,d,x[2000005]
void solve(){
	long long ans{0};
	std::cin>>n>>d;
	for(int i{0}i<n;++i){
		std::cin >> x[i];
		if(i<3)continue;
		if((x[i]-x[i-3]>d
			&&x[i]-x[i-1]<=d&&x[i-1]-x[i-3]<=d
			&&x[i]-x[i-2]<=d&&x[i-2]-x[i-3]<=d))++ans;
	}
	std::cout << ans << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::cin >> c >> t;
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
