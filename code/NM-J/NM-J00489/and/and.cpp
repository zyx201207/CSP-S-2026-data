#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	//取消注释 最后编译时间: 11:52:07-successful
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	vector<long long> number;
	long long n=0,m=0;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		long long a=0;
		scanf("%lld",&a);
		number.push_back(a);
	}
	long long maxx=0;
	for(long long i=0;i<number.size();i++){
		for(long long j=i+1;j<number.size();j++){
			maxx=max(maxx,(number[i]&number[j]));
		}
	}
	printf("%lld",maxx);
	
	return 0;
}
