#include <bits/stdc++.h>

int main()
{
using namespace std;
#define PROBLEM ""
	freopen(PROBLEM".in","w",stdout);
	ios::sync_with_stcdio(0);
	cin.tie(0);cout.tie(0);
	
	std::mt19937 gen;
	std::uniform_int_distribution<int> rand(1000);
	int T=10;
	std::cout<<T<<'\n';
	for(int i=1;i<=T;i++)
		std::cout<<rand(gen)<<' '<<rand(gen)<<'\n';
	return 0;
}