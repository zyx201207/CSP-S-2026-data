#include<bits/stdc++.h>
using namespace std;
long long p[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned int n;
	long long m,d,k,ans=0;
	cin >> n >> m;
	for(int i=0;i<=n;i++){
		cin >> p[i];
	}
	d = p[2]-p[1];
	k = floor(m/d);
	
	if(k<d*(n-1)*n/2) {
		for(int i=1;ans<k;i++){
			ans += i;
			if(ans==k) cout << i+1;
			if(ans>k) cout << i;
		}
		
		
	}else{
		cout << n;
	}

	
	return 0;
} 
