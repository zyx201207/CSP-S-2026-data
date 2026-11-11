#include<bits/stdc++.h>
using namespace std;
long long  n,a[10005];
long long  m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int biao=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			biao=1;
		}
	}
	if(biao==0){
		long long dt=m,js=1;
		while(dt-js>=0){
			dt-=js;
			js++;
		}
		cout<<min(js,n);
		return 0;
	}
	return 0; 
} 
