#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,v;
	long long x[m*m],y=0,l;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>v;
		x[i]=v;
	}
	for(int i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			y=max((x[i] | x[j]),y);
			cout<<i<<" "<<j<<"     "<<x[i]<<" "<<x[j]<<"     "<<(x[i] | x[j])<<endl; 
		}
	}
	cout<<y;
	
	fclose(stdin);
	fclose(stdout);
} 
