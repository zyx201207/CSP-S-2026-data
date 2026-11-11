#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int zj (int x,int y){
	int a=x,b=y;
	if(a==b){
		return 0;
	}
	return 2+zj(a-2,b);
}
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n[N],d[N],x[N];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>x[i];
		}
		int h=n[i];
		int cj=x[h]-x[1];
		cout<<zj(d[i],cj);
	}
	
	return 0;
} 
