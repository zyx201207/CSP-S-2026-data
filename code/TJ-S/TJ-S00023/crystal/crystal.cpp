#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
int64_t sum(std::vector<int64_t>& vec,int64_t goal,int64_t end){
	int64_t i;
	for(i=end;i>=1&&goal>=0;i--)
		goal-=vec[i];
	return end-i+2;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int64_t m,n;
	std::cin >> n >> m;
	std::vector<int64_t>vec(n);
	for(int64_t &i:vec)
		std::cin >> i;
	std::sort(vec.begin(),vec.end());
	int64_t maxi=-1;
	for(int i=1;i<n;i++){
		int j=sum(vec,m,i);
		if(maxi<j)
			maxi=j;
	}
	std::cout << maxi << std::endl;
}