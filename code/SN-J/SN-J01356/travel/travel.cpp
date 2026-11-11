#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d; 
	int p,q,m,n;
	cin >> a >> b >> c >> d;
	p=b[2];
	q=d[2];
	m = max(p,q);
	n = min(p,q);
	
	if(a==c){
		cout << 1;
		if(b[0]==d[0]&&b[1]==d[1]){
		cout << 1;
		if(m==n+1&&m!=68){
			cout << 1;
			if(m==n+1) cout << 1;
			else cout << 0;
		}else if(m==67&&n==65){
			cout << 1;
			if(m==n+1) cout << 1;
			else cout << 0;
		}else{
			cout << 0 << 0;
		}
	
	}else{
		cout << 0 << 0 << 0;
	}
	}else cout << 0 << 0 << 0 << 0;
	
	
	
	
	

	return 0;
}

