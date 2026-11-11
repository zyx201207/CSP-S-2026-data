#include<bits/stdc++.h>
using namespace std;
int n,m,cr[100000005],cnt=1;
bool c;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>cr[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n-1;j++){
			if(cr[j]<=cr[j+1]){
				cr[j]+=1;
				c=1;
			}
			if(c==1){
				c=0;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(cr[i]==cr[i+j]){
				cnt++;
				break;
			}
			else{
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
