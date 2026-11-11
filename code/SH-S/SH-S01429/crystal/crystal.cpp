#include <bits/stdc++.h>
using namespace std;

long long n,m,inp,ansMax,pL,pR,crt;
vector<long long> q;//qianzhuihe
long long a[500002];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ansMax = 1; 
	cin >> n >> m;
	//nums
	q.push_back(0);
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i=0;i<n;i++){
		q.push_back(q[i]+a[i]);
	}
	pL = 0;pR = 0;crt=0;
	while (pR < n){
		crt = (pR-pL)*a[pR] - q[pR] + q[pL];
		//cout << pL << " " << pR << " " << crt << endl; 
		if (crt <= m){
			pR++;
			ansMax = max(ansMax, pR-pL);
		}
		else pL++;
	}
	cout << ansMax;
	return 0;
}

