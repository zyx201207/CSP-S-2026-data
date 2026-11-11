#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long  n,m,f[100000],w=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	
		for(int j=0;j<m;j++){
			
	if(f[j]=f[j+1])	w=w+1;break;
	f[j]=i+1;
	f[j]+=1;	
	}
	}	
		
	
	cout<<w;
	return 0;
}
