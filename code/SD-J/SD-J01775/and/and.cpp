#include <bits/stdc++.h>
using namespace std;
long long n , m;
long long a[200005];

long long awy(long long t , long long cnt , int vis[200005]){
	cnt++;
	if(cnt > m){
		return t;
	} 
	
	long long maxx = 0;
	for(long long i = 1;i<=n;i++){
		if(vis[i] == 1) continue;
		vis[i] = 1;
		maxx = max(maxx,awy(t&a[i] , cnt , vis));
	}
	return maxx;
}

int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	long long maxx = 0;
	
	for(int i=1;i<=n;i++){
		int vis[200005];
		for(int j=1;j<=n;j++){
			vis[j] = 0;
		}
		vis[i] = 1;
		maxx = max(awy(a[i],0,vis),maxx);
	}

	cout << maxx;
	return 0;
} 
