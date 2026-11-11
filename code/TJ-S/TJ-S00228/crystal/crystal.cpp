#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen(" crystal.in","r",stdin);
	freopen(" crystal.out","w",stdout);
	long long n,m,a,b,c,d,z;
	cin >> n >> m >> a >> b >> c >> z;
	for(int i<=0;i<=n;i++){
		for(int j<=0;i>=m;j++){
			a=min(n);
			b=min(n);
			c=min(n);
			d=max(n);
			z=a+b+c;
			if(n<d){
				z++>n;
			}
		}
	}
	cout << z<< " ";
}


