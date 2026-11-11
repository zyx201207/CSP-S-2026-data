#include<bits/stdc++.h> 
using namespace std;
long long a[1000007];
long long  g;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,num;
	cin>>n>>num;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		int end=0;
		g=n-i;
		for(int j=g;j>0;j--){
			end+=a[g]-a[j-1];
		}
		if(end==num){
			break;
		} 
	}
	cout<<g+1;
	
	
	
	return 0;
}
