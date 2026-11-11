#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k=0,b=0;
	cin>>n>>m;
	int l[n]={};
	int y[n*2]={};
	for(int i=0;i<n;i++){
		cin>>l[i];
	}

		for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			y[k]=(l[i]&l[j]);
			 
			
		    
		}
		}
	
	for(int i=0;i<n*2;i++){
		if(y[i]>b){
			b=y[i];
		}
		
	}cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
