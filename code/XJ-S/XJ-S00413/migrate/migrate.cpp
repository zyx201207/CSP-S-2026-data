#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,maxx=0;
		cin>>n>>d;
		int x[n+5]={};
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=1;j<=n;j++){
			if(x[j+d+1]==x[j]+d*2-1){
				maxx++;
			}
		}
		cout<<maxx<<endl;
	}
	return 0;
}
