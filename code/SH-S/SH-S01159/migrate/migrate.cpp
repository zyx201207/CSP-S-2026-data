#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	int c,t,n;
	long long d;
	cin>>c>>t;
	long long x[200005]={0};
	for(int j=0;j<t;j++){
		fin>>n>>d;
		for(int i=0;i<n;i++){
			fin>>x[i];
		}
		long long ans=0;
		int cha=x[1]-x[0];
		int k=d/cha;
		if(k==0&&k==1){
			fout<<0;
			return 0;
		}
		for(int i=2;i<=k;i++){
			ans=ans+(n-k);
		}
		fout<<ans;
	}
	return 0;
}
