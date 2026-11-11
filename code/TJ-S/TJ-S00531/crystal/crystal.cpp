#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int v = 0;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	long long zj;
	zj = n / 2;
	long long l = a[zj];
	long long o = a[zj+1];
	long long cs = m;
	for(long long i = 0;i < n;i++){
		if(!cs){
			break;
		}
		if(a[i] < l){
			cs -= l - a[i];
			a[i] = l;	
		}else{
			break;
		}
	}
	if(zj > cs){
		for(long long i = 0;i < n;i++){
			if(a[i] == l){
				v++;
	    	}else{
	    		cout << v;
	    		return 0;
			}
		}
	}else{
		for(int i = 0;i <= zj;i++){
			if(cs == 0){
				break;
		 }
			cs--;
			a[i]++;
		}
		for(long long i = 0;i < n;i++){
			if(a[i] == o){
				v++;
	    	}else{
	    		cout << v;
	    		return 0;
			}
		}
	}
	return 0;
} 
