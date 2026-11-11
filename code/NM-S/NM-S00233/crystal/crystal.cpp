#include <bits/stdc++.h>
using namespace std;
int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n = 0,m  = 0;
	scanf("%lli%lli",&n,&m);
	vector<long long> vec1;
	for(long long i = 0;i<n;i++){
		long long t = 0;
		scanf("%lli",&t);
		vec1.push_back(t);
	}
	sort(vec1.begin(),vec1.end());
//	for(long long i = 0;i<n;i++){
//		cout<<vec1[i];
//	}
	long long k = 1;
	for(long long i = 1;i<n;i++){
		long long a = 1;
		long long x = m;
		for(long long j = i-1;j>=0;j--){
			long long t = vec1[i] - vec1[j];
			if(x-t>=0){
				a++;
				x = x-t;
			}
		}
		if(a>k){
			k = a;
		}
		
	}
	printf("%lli",k);

	return 0;
}
