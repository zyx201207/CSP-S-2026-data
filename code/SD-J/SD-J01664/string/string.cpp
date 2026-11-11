#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,ii;
string nm,nn,nmm,nmn,dao;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long j=1;j<=n;j++){
		cin>>nn;
		for(long long i=j;i<=nn[0]-'0';i++){
			nm[i*j]==nn[1];
		}	
	}
	long long mid=nm.length()/2;
	for(int i=nm.length()-1;i>=0;i--,m++){
		nmn[m]=nm[i];
	}
	for(int i=0;i<nm.length();i++){
		if(nmn[i]!=nm[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
