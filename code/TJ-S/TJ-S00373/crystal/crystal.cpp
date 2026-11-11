#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	
	for(int i=0;i<n;i++){
		b[i] = a[i+1] - a[i];
	}
	bool c = 1;
	for(int i=0;i<sizeof(b);i++){
		if(b[i] != b[i+1]){
			c = 0;
			break;
		}
	}
	int g = 1;
	if(c){
		int h = b[1];
		
		while(m != 0){
			m - h;
			h += g * (g + b[g]) / 2;
			if(h >= m){
				break;
			}
			h += g * b[1];
			g++;
		}
	}
	cout << g - 1;
	return 0;
}
