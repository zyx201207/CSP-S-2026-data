#include<bits/stdc++.h>
using namespace std;
int c,t,n[100005],d[100005],x[2000005],u,v,i,p=1;
int cx(int u,int v,int d){
	int num;
	if(x[v]-x[u] <= d){
		num++;
	}
	else{
		num += cx(u,v/d+1,d)+cx(v/d+1,v,d);
	}
	return num;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >> t;
	for(int i = 1;i<= t;i++){
		cin >> n[i] >> d[i];
		for(int j = 1;j<= n[i];j++){
			cin >> x[j];
		}
		if(n[i]==2 || n[i]==1) cout << 0<< endl;
		else cout << 1 << endl;
	}
	
	return 0;
} 
