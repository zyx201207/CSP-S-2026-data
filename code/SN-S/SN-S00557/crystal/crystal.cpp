#include <bits/stdc++.h>
using namespace std;
long long n,m,bmin,f,s,g,a[1000005];
int main(){
	freopen("crystal.in ","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	sort(a,a+n+1);
	while(m > 0){	
		for(int i=1;i<=n;i++){
			if(i==1){
				bmin = a[n];
			}else{
				f = a[i] - a[i-1];
			}
			if(bmin > f){
				if(f != 0){
					bmin = f;
					g = i-1;
				}
			}	
		}
		if(m > bmin){
			a[g] = a[g+1];
			s = s+1;
			m = m-bmin;
		}else{
			break;
		}	
	}
	cout << s+1;	
	return 0;
}
