#include <bits/stdc++.h>
using namespace std;
string x1,x2,y;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n,k,cnt = 0,tnt=0;
	
	cin >> n;
	for (long i = 1; i <= n;i++){
		cin >> k >> y;
		for (long j = 1;j <= k;j++){
			x1.append(y);
			
		}
		tnt += k;
	}
	bool flag = true;
	long long p = 0,q = tnt - 1;
	
	while(p < q){
		if (x1[p] != x1[q]){
			flag = false;
			cnt++;
        
		}
        
		p++;
		q--;
		
		
	}
	if (p == q){
		if (x1[p] != x1[q]){
			flag = false;
			cnt++;
		}
	}
	
	
	
	if (flag == true){
		cout << 0;
		return 0;
	}


	cout << cnt;
	return 0;
} 
