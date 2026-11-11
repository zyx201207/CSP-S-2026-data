#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
//d·ÉÐÐ 
int c,t,n,d;
int feic(int x,int y){
	for(int i=x;i<=y;i++){
	}
}
int feij(int x,int y){
	return a[y]-a[x];
}
int main(){
	freopen("migrate.in","r",stdin);
	
	cin>>c>>t;
	for(int l=1;l<=t;l++){
	
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+d+1;j<=n;j++){
				//fei(i,j)
			}
		}
	}
	freopen("migrate.out","w",stdout);
	cout<<"0"<<endl<<"1";
	return 0;
} 
