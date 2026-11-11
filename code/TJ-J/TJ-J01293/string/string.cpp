#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in" , "r", stdin );
	freopen("string.out", "w", stdout); 
	
	unsigned int n;
	cin >> n;
	
	char                   cs[n]     , cfs[n]  ;
	unsigned long long int nums[n]   , numfs[n];
	unsigned int           numcnt = 0, len = 0 ;
	
	int i = 0;
	for (int j=0; j<n; j++) {
		unsigned int a;
		char         c;
		
		cin >> a >> c;
		len += a;
		
		if (i == 0 || c != cs[i - 1]) {
			nums[i] = a;
			cs[i]   = c;
			numcnt  ++;
			i++;
		} else {
			nums[i - 1] += a;
		}
	}
	
	if (numcnt == 1) {
		cout << 0;
		return 0;
	}
	
	for (int j=0; j<i; j++) {
		numfs[i - 1 - j] = nums[j];
		cfs  [i - 1- j] = cs[j];
	}
	unsigned long long int cnt = 0;
	
	unsigned long long int num = nums[0], numf = numfs[0];
	unsigned int           ind = 0      , indf = 0;
	char                   c = cs[0]    , cf = cfs[0];
	
	
	while ((int)(numcnt - ind - indf) > 0) {
		unsigned long long int del = min(num, numf);
		
		if (c != cf) {
			cnt += del;
		}
		if (num < numf) {
			ind++;
			c   = cs  [ind];
			num = nums[ind];
			
			numf -= del;
		} else if (num == numf) {
			ind ++;
			indf++;
			c    = cs   [ind] ;
			cf   = cfs  [indf];
			num  = nums [ind];
			numf = numfs[indf];
		} else {
			indf ++;
			cf   = cfs  [indf];
			numf = numfs[indf];
			
			num -= del;
		}
	}
	
	cout << cnt;
	
	fclose(stdin );
	fclose(stdout);
	
	return 0;
}
