#include <bits/stdc++.h>
using namespace std;

long long ccf,n,d,i1,i2,t,k;
vector<long long> isl;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> ccf >> t;
	while (t--){
		isl.clear();
		cin >> n >> d;
		long long cnt = 0;
		for (int i=0;i<n;i++){
			cin >> i1;
			isl.push_back(i1);	
		}
		if (isl.size()>=2){
			k = isl[1]-isl[0];
			if (d>=2*k)cnt = max(isl.size()-(d/k)*2+1,0ULL);
		}
		cout << cnt << "\n";
		
	} 
	return 0;
}

