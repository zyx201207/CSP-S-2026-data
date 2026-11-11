#include<bits/stdc++.h>
using namespace std;
string k,k1,k2;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,m,z=0;
	cin>>n;
	string a;
	for(int i=0;i<n;i++){
		cin>>m>>a;
		for(int j=0;j<m;j++){
			k+=a; 
		}
	} 
	if(k.size()%2==0){
		int u=0;
		for(int i=0;i<k.size()/2;i++){
			k1[i]=k[i];
		}
		for(int i=k.size();i>=k.size()/2;i--){
			k2[u]=k[i];
			u++;
		}
		for(int i=0;i<=k.size()/2;i++){
			if(k1[i]!=k2[i]) z++; 
		}
	}
	if(k.size()%2==1){
		int p=0; 
		for(int i=0;i<(k.size()-1)/2;i++){
			k1[i]=k[i];
		}
		for(int i=k.size();i>(k.size()-1)/2;i--){
			k2[p]=k[i];
			p++;
		}
		for(int i=0;i<=(k.size()-1)/2;i++){
			if(k1[i]!=k2[i]) z++; 
		}  
	}
    cout<<z-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
