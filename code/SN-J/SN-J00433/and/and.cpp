#include<bits/stdc++.h>
using namespace std;
#define PID "and"
#define FIN freopen(PID ".in"."r"stdin);
#define FOU forepen(PID ".out"."w"stdout);
long long a[1001];
signed main(){
	int c,b;
	cin>>c>>b;
	for(int i=0;i<=c;i++){
		cin>>a[c];
		cin>>a[b];
		if(a[c]>a[b]){
			a[b]=b;
		}
	}
	cout<<b;
	return 0;
}
