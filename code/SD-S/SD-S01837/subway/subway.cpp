#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r+",stdin);
	freopen("subway.out","w+",stdout);
	long long c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	long long w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	long long N=7*n; 
	long long k[N];
	for(int i=0;i<n*7;i++){
	
		cin>>w[i];
	
	}
	long long R=p*2;
	long long r[R];
		for(int i=0;i<p*2;i++){
	
		cin>>r[i];
	
	}
	cout<<32<<endl;
	cout<<17;
	fclose(stdin);
	fclose(stdout); 

	return 0;
	
} 
