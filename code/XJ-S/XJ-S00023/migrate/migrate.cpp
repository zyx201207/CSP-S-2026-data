#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long c,t,n,x,s[2000005]={},sh[2000005]={},ss=0,hh[2000005]={},hhh=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>x;
		for(int j=1;j<=n;j++){
			cin>>s[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n-x;k++){
				sh[ss]=k+3;
				ss++;
			}
		}
		for(int j=0;j<ss;j++){
			int h=0;
			for(int k=0;k<ss;k++){
				if(sh[k]==sh[j]){
					h++;
				}
			}
			if(h==2){
				hh[hhh]++;
			}
		}
		hhh++;
	}
	for(int i=0;i<hhh;i++){
		cout<<hh[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
