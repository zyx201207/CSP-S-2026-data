#include <iostream>
#include <cstring>
using namespace std;
bool c[1000];
int main(){
	int n,m;
	cin>>n>>m;
	int a[m+1];
	int b[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}for(int i=1;i<=m;i++){
		c[i]=false;
		a[i]=0;
	}
	for(int t=1;t<=n;t++){
		c[b[t]]=true;
		for(int i=t+1;i<=n;i++){
			if(!c[b[i]]){
				c[b[i]]=true;
			}else{
				for(int j=i-1;j>=2;j--){
					c[b[i]]=false;
					if(b[i]==b[j]) break;
				}c[b[i]]=true;
			}
		}for(int l=1;l<=m;l++){
			if(c[l]){
				a[l]++;
			}
		}for(int d=1;d<=m;d++){
			c[d]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 
