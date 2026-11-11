#include <bits/stdc++.h>
using namespace std;

int ttt(int tx,int ty,long long tz){
	int y2=pow(2,ty);
	if(tx>1&&y2>tx) return ttt(tx,ty-1,tz*10);
	if(tx<=1||ty<=0) return tz*pow(10,ty)*10+tx;
	return ttt(tx-y2,ty-1,tz*10+1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	long long a[n+10];
	for(int i=1; i<=n; i++){
		int ai;
		cin >> a[i];
		ai=ttt(a[i],20,0);
	}
	int u=0;
	for(int i=1; i<=n; i++){
		if(a[i]>u) u=a[i];
	}
	cout << u;
	return 0;
} 
