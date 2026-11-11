#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000005];
int pathroad(int u,int v){
	int step=(x[v]-x[u]+d-1)/d;
	if((double)step*d-(double)(x[v]-x[u])>(double)d/2.1)return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int tn=0; tn<t; tn++){
		cin >> n >> d;
		for ( int i=0; i<n; i++){
			cin >> x[i];
		}
		int cnt=0;
		for ( int i=0; i<n-1; i++){
			for ( int j=i+1; j<n; j++){
				cnt+=pathroad(i,j);
			}
		}
		cout << (int)(cnt/2.5) << endl;
	}
}
