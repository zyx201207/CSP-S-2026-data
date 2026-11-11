#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,t,co=0;
	int n[9999999],d[99999999],x[99999999][99999999],turn[9999999][9999999];
	bool used[9999999][9999999];
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=t;j++){
			cin>>x[i][j];
		}
	}
	for(int i=1;i<=t;i++){
		co=0;
		for(int j=1;j<=t;j++){
			for(int k=j+1;k<=t;k++){
				if(x[k]-x[j]<=d[i]&&used[i][k]!=true){
					turn[i][j]++;	
					j=k;
					used[i][k]=true;
				}
			}
			if(turn[i][j]==turn[i][j-1]&&j>1){
				co++;
			}
		}
		cout<<co<<endl;
	}
	return 0;
}
