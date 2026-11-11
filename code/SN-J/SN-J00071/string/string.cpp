#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char u,r[10080];
	int g,h,j=0;
	cin>>g;
	for(int i=0;i<g;i++){
		cin>>r[i];
	}
	if(g%2==0){
		for(int i=0;i<=(g-1)/2;i++){
			if(r[i]!=r[g-1-i]){
				j++;
			}
		}
	}else{
		for(int i=0;i<=(g-1)/2;i++){
			if(r[i]!=r[g-1-i]){
				j++;
			}
		}
		
	}
	cout<<j;
}
