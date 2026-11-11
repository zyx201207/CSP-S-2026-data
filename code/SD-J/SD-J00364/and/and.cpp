#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[200001];
bool b[40];
int main(){
	cin>>m>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = 30;j>0;j--){
			if(a[i]-pow(2,j)>=0){
				b[j] = true;
			}else{
				continue;
			}
		}
	}
	if(n == m){
		for(int i = 0;i<=30;i++){
			
		}
	}
}
