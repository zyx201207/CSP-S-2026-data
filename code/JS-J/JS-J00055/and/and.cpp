#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> vec;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vec.resize(n);
	for(int i=0;i<n;++i){
		cin>>vec[i];
	}
	long long maxn=-1e17;
	for(long long i=1;i<=(1<<n);++i){
		int cnt=0,i1=i;
		while(i1>0){
			if(i1%2==1) cnt++;
			i1>>=1;
		}
		if(cnt!=m) continue;
		long long sum=-1;
		i1=i;
		cnt=0;
		while(i1>0){
			if(i1%2==1){
				if(sum==-1) sum=vec[cnt];
				else sum&=vec[cnt];
			}
			i1>>=1;
			cnt++;
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
