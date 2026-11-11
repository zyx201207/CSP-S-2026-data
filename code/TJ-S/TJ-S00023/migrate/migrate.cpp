#include <iostream>
#include <queue>
#include <vector>

struct pt{
	int num;
	int steps;
};

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int c,t;
	std::cin >> c >> t;
	for(int cms=0;cms<t;cms++){
	int n,d;
	std::cin >> n >> d;
	std::vector<int>fx(n);
	for(int i=0;i<n;i++)
		std::cin >> fx[i];
	std::vector<std::vector<pt>>dp(n,std::vector<pt>(n));
	for(int i=0;i<n;i++){
		for(int k=i+1;k<n&&fx[k]-fx[n]<=d;k++){
			dp[i][k]={1,1};
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(dp[i][j].num==1)
				continue;
			int sum=0;
			for(int k=j-1;k>=i&&fx[j]-fx[k]<=d;k--)
				sum+=dp[i][k].num;
			dp[i][j]={dp[i][j-1].steps+1,sum};
			if(sum>1){
				ans++;
				std::cout << i << "to" << j << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << ans <<std::endl;
}
}