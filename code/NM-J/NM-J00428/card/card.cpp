#include <bits/stdc++.h>
using namespace std;
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	long long n = 0,m = 0;
	scanf("%lli%lli",&n,&m);
	vector<long long> vec1;
	vec1.push_back(0);
	map<long long,long long> mp;
	for(long long i = 1;i<=n;i++){
		long long t = 0;
		scanf("%lli",&t);
		mp[t] = 0;	
		vec1.push_back(t);
	}
	map<long long,long long> mp2;
	for(long long i = 1;i<=n;i++){
		vector<long long> vec2(500005);
		long long t1 = vec1[i];
		long long k1 = i;
		vec2[k1] = t1;
//		cout<<vec2[k];
		mp[t1] = i;
//		cout<<mp[t1];
		for(long long j = i+1;j<=n;j++){
			k1++;
			long long t2 = vec1[j];
			if(mp[t2] != 0){
				k1 = mp[t2];
				for(long long k = k1+1;k<=n;k++){
					vec2[k] = 0;
				}
			}
			vec2[k1] = t2;
			mp[t2] = j;
//			cout<<k1;
		}
		
		for(long long j = 1;j<=n;j++){
			long long t3 = vec2[j];
			mp2[t3]++;
		}
	}
	for(long long i = 1;i<=m;i++){
		printf("%lli ",mp2[i]);
	}

	return 0;
}
