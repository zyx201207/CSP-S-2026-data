#include <bits/stdc++.h>
using namespace std;
long long A[200500];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,i,m,a,b,d1,d2,x1,x2;
	cin>>n>>m;
	if(n <= 20 || n > 2000){
		for(i = 1;i <= n;i++) cin>>A[i];
		sort(A + 1,A + 1 + n);
		cout<<A[n - m + 1];
	}
	else{
		cin>>a;
		cin>>b;
		d1 = max(a,b);
		x1 = min(a,b);
		d2 = x1;
		x2 = d1;
		for(i = 3;i <= n;i++){
			cin>>a;
			cout<<" "<<i<<endl;
			if(a >= d1){
				d2 = d1;
				d1 = a;
			}
			else{
				if(a > d2) d2 = a;
			}
			if(a <= x1){
				x2 = x1;
				x1 = a;
			}
			else{
				if(a < x2) x2 = a;
			}
		}
		if(m == 1) cout<<d1;
		else if(m == 2) cout<<d2;
		else if(m == n) cout<<x1;
		else if(m == (n - 1)) cout<<x2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
