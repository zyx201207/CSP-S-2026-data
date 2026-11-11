#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r","stdin");
	//freopen("string.out","w","stdout");
	int n;
	cin>>n;
	long long a[100000]={},b[1000000000]={};
	string g="";
	bool x=0;
	int cs=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		g=a[i]*b[i];
	}
	for(int i=0;i<n;i++){
		if(g[i]==g[g.size()-i]){
			x==1;
		}
		else if(g[i]!=g[g.size()-i]){
			g[g.size()-i]=g[i];
			cs++;
		}
	}
	
return 0;
}