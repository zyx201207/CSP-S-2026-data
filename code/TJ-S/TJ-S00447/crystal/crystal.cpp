#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[n]={};
	int ai[n],s,h,t=0,k=0;
	int ji,min=0,q,c=0;
	for(int i=0;i<n;i++){
		cin>>ai[i];
	}for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(ai[j]<ai[j+1]){
				s=ai[j];
				ai[j]=ai[j+1];
				ai[j+1]=s;
			}
		}
	}for(int i=0;i<n;i++){
		t=0;
		h=ai[i];
		for(int j=i+1;j<n;j++){
			if(t+h-ai[j]>m){
				break;
			}else{
				t+=h-ai[j];
				x[i]+=1;
			}
		}
	}for(int j=0;j<n;j++){
		if(k<x[j]){
			k=x[j];
		}
	}cout<<k+1;
	return 0; 
}
