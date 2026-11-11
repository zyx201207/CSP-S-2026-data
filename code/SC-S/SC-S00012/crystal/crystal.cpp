#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
	for(int i=0;i<n;i++){
		int a1[n];
		cin>>a1[i];	
		for(int y=0;y<=n;y++)
		if(a1[y]+m-a1[y+1]==a1[y+2]){
			for(int k=1;k<=n;k++){
				if(k==(a1[y]+a1[y+1]+m+a1[y+2])/a1[y+2]){
					if(a1[y]==a1[y+1]){
						cout<<k+2;
						return 0;
					}
					cout<<k;
				}
			}
			return 0;
	
			
		}
    } 
}