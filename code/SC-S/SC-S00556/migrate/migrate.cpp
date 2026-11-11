#include<bits/stdc++.h>
using namespace std;
long long ans[10000]={};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		long long n,d;
		cin>>n>>d;
		long long x[n];
		//bool u[1000000000000000001]={};
		for(int j=0;j<n;j++){
			cin>>x[i];
			//u[x[i]]=1;
		}
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++) if(x[j]+2*d>=x[k]/*||(x[j]+3*d>=x[k]&&x[j]+2*d<x[k])*/) ans[i]++;
		}
	}
	for(int i=0;i<t;i++) cout<<ans[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}